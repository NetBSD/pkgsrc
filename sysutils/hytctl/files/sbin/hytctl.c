/*
 * $Header: /cvsroot/pkgsrc/sysutils/hytctl/files/sbin/hytctl.c,v 1.1 2015/09/06 06:50:53 kardel Exp $
 *
 * $Created: Fri May 16 20:29:08 2014 $
 */

 /*-
 * Copyright (c) 2015 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Frank Kardel.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__RCSID("$NetBSD: hytctl.c,v 1.1 2015/09/06 06:50:53 kardel Exp $");

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/gpio.h>
#include "hytp14reg.h"

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <util.h>

#include <dev/i2c/i2c_io.h>

#define ARG_GPIODEV    1
#define ARG_GPIOPIN    2
#define ARG_I2CDEV     3
#define ARG_I2CADDR    4
#define ARG_EEPROMADDR 5
#define ARG_EEPROMVAL  6

static int debug = 0;

__dead static void
usage(void)
{
	fprintf(stderr, "usage: %s [-d] <gpio-dev> <pin#|pin-name> <i2c-dev> <i2c-addr> <eeprom-address> [<new eeprom value>]\n", getprogname());
	exit(EXIT_FAILURE);
}

static void
waitfor(int usec)
{
	struct timeval tv1;
	struct timeval tv2;
	
	gettimeofday(&tv1, NULL);

	tv2.tv_sec   = tv1.tv_sec + usec / 1000000;
	tv2.tv_usec  = tv1.tv_usec + usec % 1000000;
	tv2.tv_sec  += tv2.tv_usec / 1000000;
	tv2.tv_usec %= 1000000;

	while (tv2.tv_sec > tv1.tv_sec || (tv2.tv_usec > tv1.tv_usec && tv2.tv_sec == tv1.tv_sec)) {
		gettimeofday(&tv1, NULL);
	}
}

static int
iic_write(int fd, i2c_addr_t addr, int clen, uint8_t *cmd, int blen, uint8_t *buf)
{
	i2c_ioctl_exec_t iie;

	iie.iie_op = I2C_OP_WRITE_WITH_STOP;
	iie.iie_addr = addr;
	iie.iie_cmd = cmd;
	iie.iie_cmdlen = clen;
	iie.iie_buf = buf;
	iie.iie_buflen = blen;

	if (ioctl(fd, I2C_IOCTL_EXEC, &iie) == -1) {
		return errno;
	}

	return 0;
}

static int
iic_read(int fd, i2c_addr_t addr, int clen, uint8_t *cmd, int blen, uint8_t *buf)
{
	i2c_ioctl_exec_t iie;

	iie.iie_op = I2C_OP_READ_WITH_STOP;
	iie.iie_addr = addr;
	iie.iie_cmd = cmd;
	iie.iie_cmdlen = clen;
	iie.iie_buf = buf;
	iie.iie_buflen = blen;

	if (ioctl(fd, I2C_IOCTL_EXEC, &iie) == -1) {
		return errno;
	}
	
	return 0;
}

static int
exec_cmd(int fd, i2c_addr_t addr, int cmdlen, uint8_t *cmd, int datalen, uint8_t *data)
{
	int error;
	
	/* send command */
	if ((error = iic_write(fd, addr, cmdlen, cmd, 0, NULL)) == 0)
	{
		int loops = 0;
		
		for (;;) {
			/* read reply */
			memset(data, 0, datalen);
			
			if ((error = iic_read(fd, addr, 0, NULL, sizeof data, data)) == 0)
			{
				if (data[0] & HYTP14_RESP_CMDMODE) {
					char b[80];
					
					snprintb(b, sizeof b, HYT_STATUS_FMT,
						 data[0]);
					
					if (debug) {
						fprintf(stderr, "CM_MODE command 0x%02x status=%s\n", cmd[0], b);
					}
				} else {
					if (cmd[0] != HYTP14_CMD_START_NOM)
						fprintf(stderr, "CM mode command 0x%02x unexpectedly turned off\n", cmd[0]);
					return 0;
				}
				
				switch (data[0] & HYTP14_RESP_MASK)
				{
				case HYTP14_RESP_ACK:
					return 1;
						
				case HYTP14_RESP_NACK:
					fprintf(stderr, "Command 0x%02x failed with NACK\n", cmd[0]);
					return 0;

				case HYTP14_RESP_BUSY:
					/* do not wait forever for an ACK */
					if (++loops > 100) {
						fprintf(stderr, "result wait loop count exceeded\n");
						return 0;
					}
				}
			} else {
				if (cmd[0] != HYTP14_CMD_START_NOM)
					fprintf(stderr, "Command 0x%02x READ failed (errno=%d)\n", cmd[0], error);
				return 0;
			}
		}
	} else {
		fprintf(stderr, "Command 0x%02x WRITE failed (errno=%d)\n", cmd[0], error);
		return 0;
	}
}

int
main(int argc, char *argv[])
{
	int argidx = 0;
	int gfd, fd, error;
	i2c_addr_t addr = HYTP14_DEFAULT_ADDR;
	int eeaddr = 0;
	uint8_t data[4];
	uint8_t cmd[3];
	int count = 0;
	char *endptr;
	long gpio_pinnumber = -1;
	int pinstatus;
	struct gpio_info gpioinfo;
	struct gpio_req  gpioreq;
	struct gpio_set  gpioset;

	setprogname(*argv);

	if ((argc > 1) && (strcmp(argv[1], "-d") == 0)) {
		debug = 1;
		argidx = 1;
	}
		
	if ((argc-argidx) <= ARG_EEPROMADDR) {
		usage();
	}
	
	fd = open(argv[argidx + ARG_I2CDEV], O_RDWR);
	if (fd == -1) {
		err(EXIT_FAILURE, "couldn't open %s", argv[argidx + ARG_I2CDEV]);
	}
	
	addr = strtol(argv[argidx + ARG_I2CADDR], &endptr, 0);
	if (addr < 1 || addr > 0x7f || argv[argidx + ARG_I2CADDR][0] == '\0' || *endptr != '\0') {
		err(EXIT_FAILURE, "I2C address (%s) is invalid", argv[argidx + ARG_I2CADDR]);
	}
  
	eeaddr = strtol(argv[argidx + ARG_EEPROMADDR], &endptr, 0);
	if (eeaddr < 0 || eeaddr >= HYTP14_NUM_WORDS || argv[argidx + ARG_EEPROMADDR][0] == '\0' || *endptr != '\0') {
		err(EXIT_FAILURE, "HYT EEPROM address (%s) is invalid", argv[argidx + ARG_EEPROMADDR]);
	}
  
	gpio_pinnumber = strtol(argv[argidx + ARG_GPIOPIN], &endptr, 0);
	if (argv[argidx + ARG_GPIOPIN][0] != '\0' && *endptr == '\0') {
		gpioreq.gp_pin = gpio_pinnumber;
		gpioreq.gp_name[0] = '\0';
		gpioset.gp_pin = gpio_pinnumber;
		gpioset.gp_name[0] = '\0';
	} else {
		gpioreq.gp_pin = -1;
		strncpy(gpioreq.gp_name, argv[argidx + ARG_GPIOPIN],
			sizeof gpioreq.gp_name);
		gpioset.gp_pin = -1;
		strncpy(gpioset.gp_name, argv[argidx + ARG_GPIOPIN],
			sizeof gpioset.gp_name);
	}
	gpioset.gp_flags = 0;
	gpioset.gp_name2[0] = '\0';
  
	gfd = open(argv[argidx + ARG_GPIODEV], O_RDWR);
	if (gfd == -1) {
		err(EXIT_FAILURE, "couldn't open %s", argv[argidx + ARG_GPIODEV]);
	}
	
	if (ioctl(gfd, GPIOSET, &gpioset) == -1) {
		err(EXIT_FAILURE, "failed getting GPIO configuration");
	}
	
	if (debug) {
		printf("GPIO: Pin %d (%s) flags: 0x%x\n",
		       gpioset.gp_pin, gpioset.gp_name, gpioset.gp_flags);
	}
	
	if ((gpioset.gp_flags & (GPIO_PIN_OUTPUT|GPIO_PIN_INOUT)) == 0) {
		err(EXIT_FAILURE, "Pin %d (%s) not configured for output",
		    gpioset.gp_pin, gpioset.gp_name);
	}

	if (ioctl(gfd, GPIOREAD, &gpioreq) == -1) {
		err(EXIT_FAILURE, "failed getting GPIO status");
	}
	
	if (debug) {
		printf("GPIO: Pin %d (%s) state %s\n",
		       gpioreq.gp_pin, gpioreq.gp_name,
		       (gpioreq.gp_value == GPIO_PIN_HIGH) ? "HIGH" : "LOW");
	}
	
	pinstatus = gpioreq.gp_value;
	
	if (gpioreq.gp_value == GPIO_PIN_HIGH) {
		gpioreq.gp_value = GPIO_PIN_LOW;
	  
		if (ioctl(gfd, GPIOWRITE, &gpioreq) == -1) {
			err(EXIT_FAILURE, "failed switching off gpio pin");
		}
	}

	waitfor(10000);

	gpioreq.gp_value = GPIO_PIN_HIGH;
  
	if (ioctl(gfd, GPIOWRITE, &gpioreq) == -1) {
		err(EXIT_FAILURE, "failed switching on gpio pin");
	}
	
	waitfor(1000);
  
	memset(data, 0, sizeof data);
	memset(cmd, 0, sizeof cmd);

	cmd[0] = HYTP14_CMD_START_CM;
  
	/* send START_CM command */
	while (!exec_cmd(fd, addr, sizeof cmd, cmd, sizeof data, data)
	       && ++count < 3)
		/* empty */;

	if (count >= 3) {
		printf("FAILED entering CM mode\n");
	} else {
		cmd[0] = HYTP14_CMD_GET_REV;
	  
		if (exec_cmd(fd, addr, sizeof cmd, cmd, sizeof data, data))
		{
			printf("Revision = 0x%02x%02x\n", data[1], data[2]);
		} else {
			errc(EXIT_FAILURE, error,
			     "sending GET_REV command to %s address 0x%x",
			     argv[argidx + ARG_I2CDEV], addr);
		}

		cmd[0] = HYTP14_READ_EEPROM(eeaddr);
	  
		if (exec_cmd(fd, addr, sizeof cmd, cmd, sizeof data, data))
		{
			printf("EEPROM(0x%02x) = 0x%02x%02x\n",
			       eeaddr, data[1], data[2]);
		} else {
			errc(EXIT_FAILURE, error,
			     "sending READ_EEPROM command to %s address 0x%x",
			     argv[argidx + ARG_I2CDEV], addr);
		}

		if (argc > argidx + ARG_EEPROMVAL) {
			long val;
			
			val = strtol(argv[argidx + ARG_EEPROMVAL], &endptr, 0);
			if (argv[argidx + ARG_EEPROMVAL][0] == '\0' || *endptr != '\0') {
				err(EXIT_FAILURE,
				    "EEPROM value (%s) is invalid",
				    argv[argidx + ARG_EEPROMVAL]);
			}

			cmd[0] = HYTP14_WRITE_EEPROM(eeaddr);
			cmd[1] = (val >> 8) & 0xFF;
			cmd[2] = val & 0xFF;
			
			if (exec_cmd(fd, addr,
				     sizeof cmd, cmd, sizeof data, data))
			{
				printf("EEPROM(0x%02x) set to 0x%02x%02x\n",
				       eeaddr, cmd[1], cmd[2]);

				memset(cmd, 0, sizeof cmd);
				cmd[0] = HYTP14_READ_EEPROM(eeaddr);
	  
				if (exec_cmd(fd, addr, sizeof cmd, cmd,
					     sizeof data, data))
				{
					printf("EEPROM(0x%02x) = 0x%02x%02x\n",
					       eeaddr, data[1], data[2]);
				}
				else
				{
					errc(EXIT_FAILURE, error,
					     "sending READ_EEPROM command to %s address 0x%x",
					     argv[argidx + ARG_I2CDEV], addr);
				}
			} else {
				errc(EXIT_FAILURE, error,
				     "sending WRITE_EEPROM command to %s address 0x%x",
				     argv[argidx + ARG_I2CDEV], addr);
			}
		}

		/* leave command mode */
		memset(cmd, 0, sizeof cmd);
		cmd[0] = HYTP14_CMD_START_NOM;

		exec_cmd(fd, addr, sizeof cmd, cmd, sizeof data, data);
	}
  
	/* restore original pin status */
	gpioreq.gp_value = pinstatus;
  
	if (ioctl(gfd, GPIOWRITE, &gpioreq) == -1) {
		err(EXIT_FAILURE, "failed restoring gpio pin status");
	} else {
		if (debug) {
			printf("GPIO: Pin %d (%s) state %s\n",
			       gpioreq.gp_pin, gpioreq.gp_name,
			       (gpioreq.gp_value == GPIO_PIN_HIGH) ? "HIGH" : "LOW");
		}
	}
	
	close(gfd);
  
	close(fd);

	return EXIT_SUCCESS;
}

/*
 * $Log: hytctl.c,v $
 * Revision 1.1  2015/09/06 06:50:53  kardel
 * Added hytctl utility to manage HYT 221/271/939 EEPROMS
 *
 */
