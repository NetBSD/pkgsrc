/* $NetBSD: bsd-tap.c,v 1.1 2020/03/04 07:52:11 rin Exp $ */
/* Id: bsd-bpf.c,v 1.9 2007/02/21 01:24:50 fredette Exp  */

/* host/bsd/bsd-tap.c - BSD TAP Ethernet support: */

/*
 * Copyright (c) 2001, 2003 Matt Fredette
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Matt Fredette.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <tme/common.h>
_TME_RCSID("Id: bsd-bpf.c,v 1.9 2007/02/21 01:24:50 fredette Exp ");

/* includes: */
#include "bsd-impl.h"
#include <tme/generic/ethernet.h>
#include <tme/threads.h>
#include <tme/misc.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <net/if.h>
#include <netinet/in_systm.h>
#include <netinet/in.h>
#if defined(HAVE_SYS_SOCKIO_H)
#include <sys/sockio.h>
#elif defined(HAVE_SYS_SOCKETIO_H)
#include <sys/socketio.h> 
#endif /* HAVE_SYS_SOCKETIO_H */
#include <sys/ioctl.h>
#ifdef HAVE_IOCTLS_H
#include <ioctls.h>
#endif /* HAVE_IOCTLS_H */
#ifdef HAVE_NET_IF_ETHER_H
#include <net/if_ether.h>
#endif /* HAVE_NET_IF_ETHER_H */
#ifdef HAVE_NET_ETHERNET_H
#include <net/ethernet.h>
#endif /* HAVE_NET_ETHERNET_H */
#include <netinet/ip.h>
#ifdef HAVE_NET_IF_DL_H
#include <net/if_dl.h>
#endif /* HAVE_NET_IF_DL_H */
#include <arpa/inet.h>

/* macros: */

/* ARP and RARP opcodes: */
#define TME_NET_ARP_OPCODE_REQUEST	(0x0001)
#define TME_NET_ARP_OPCODE_REPLY	(0x0002)
#define TME_NET_ARP_OPCODE_REV_REQUEST	(0x0003)
#define TME_NET_ARP_OPCODE_REV_REPLY	(0x0004)

/* the callout flags: */
#define TME_BSD_TAP_CALLOUT_CHECK	(0)
#define TME_BSD_TAP_CALLOUT_RUNNING	TME_BIT(0)
#define TME_BSD_TAP_CALLOUTS_MASK	(-2)
#define  TME_BSD_TAP_CALLOUT_CTRL	TME_BIT(1)
#define  TME_BSD_TAP_CALLOUT_READ	TME_BIT(2)

/* structures: */

/* our internal data structure: */
struct tme_bsd_tap {

  /* backpointer to our element: */
  struct tme_element *tme_bsd_tap_element;

  /* our mutex: */
  tme_mutex_t tme_bsd_tap_mutex;

  /* our reader condition: */
  tme_cond_t tme_bsd_tap_cond_reader;

  /* the callout flags: */
  unsigned int tme_bsd_tap_callout_flags;

  /* our Ethernet connection: */
  struct tme_ethernet_connection *tme_bsd_tap_eth_connection;

  /* the TAP file descriptor: */
  int tme_bsd_tap_fd;

  /* the packet buffer for the interface: */
  tme_uint8_t *tme_bsd_tap_buffer;

  int tme_bsd_tap_buffer_in_bytes;

  /* when nonzero, the packet delay sleep time, in microseconds: */
  unsigned long tme_bsd_tap_delay_sleep;

  /* when nonzero, the packet delay is sleeping: */
  int tme_bsd_tap_delay_sleeping;
};

/* a crude ARP header: */
struct tme_net_arp_header {
  tme_uint8_t tme_net_arp_header_hardware[2];
  tme_uint8_t tme_net_arp_header_protocol[2];
  tme_uint8_t tme_net_arp_header_hardware_length;
  tme_uint8_t tme_net_arp_header_protocol_length;
  tme_uint8_t tme_net_arp_header_opcode[2];
};

/* a crude partial IPv4 header: */
struct tme_net_ipv4_header {
  tme_uint8_t tme_net_ipv4_header_v_hl;
  tme_uint8_t tme_net_ipv4_header_tos;
  tme_uint8_t tme_net_ipv4_header_length[2];
};

/* the tap callout function.  it must be called with the mutex locked: */
static void
_tme_bsd_tap_callout(struct tme_bsd_tap *tap, int new_callouts)
{
  struct tme_ethernet_connection *conn_eth;
  int callouts, later_callouts;
  unsigned int ctrl;
  int rc;
  int status;
  tme_ethernet_fid_t frame_id;
  struct tme_ethernet_frame_chunk frame_chunk_buffer;
  tme_uint8_t frame[TME_ETHERNET_FRAME_MAX];
  
  /* add in any new callouts: */
  tap->tme_bsd_tap_callout_flags |= new_callouts;

  /* if this function is already running in another thread, simply
     return now.  the other thread will do our work: */
  if (tap->tme_bsd_tap_callout_flags & TME_BSD_TAP_CALLOUT_RUNNING) {
    return;
  }

  /* callouts are now running: */
  tap->tme_bsd_tap_callout_flags |= TME_BSD_TAP_CALLOUT_RUNNING;

  /* assume that we won't need any later callouts: */
  later_callouts = 0;

  /* loop while callouts are needed: */
  for (; (callouts = tap->tme_bsd_tap_callout_flags) & TME_BSD_TAP_CALLOUTS_MASK; ) {

    /* clear the needed callouts: */
    tap->tme_bsd_tap_callout_flags = callouts & ~TME_BSD_TAP_CALLOUTS_MASK;
    callouts &= TME_BSD_TAP_CALLOUTS_MASK;

    /* get our Ethernet connection: */
    conn_eth = tap->tme_bsd_tap_eth_connection;

    /* if we need to call out new control information: */
    if (callouts & TME_BSD_TAP_CALLOUT_CTRL) {

      /* form the new ctrl: */
      ctrl = 0;
      if (tap->tme_bsd_tap_buffer_in_bytes > 0) {
	ctrl |= TME_ETHERNET_CTRL_OK_READ;
      }

      /* unlock the mutex: */
      tme_mutex_unlock(&tap->tme_bsd_tap_mutex);
      
      /* do the callout: */
      rc = (conn_eth != NULL
	    ? ((*conn_eth->tme_ethernet_connection_ctrl)
	       (conn_eth,
		ctrl))
	    : TME_OK);
	
      /* lock the mutex: */
      tme_mutex_lock(&tap->tme_bsd_tap_mutex);
      
      /* if the callout was unsuccessful, remember that at some later
	 time this callout should be attempted again: */
      if (rc != TME_OK) {
	later_callouts |= TME_BSD_TAP_CALLOUT_CTRL;
      }
    }
      
    /* if the Ethernet is readable: */
    if (callouts & TME_BSD_TAP_CALLOUT_READ) {

      /* unlock the mutex: */
      tme_mutex_unlock(&tap->tme_bsd_tap_mutex);
      
      /* make a frame chunk to receive this frame: */
      frame_chunk_buffer.tme_ethernet_frame_chunk_next = NULL;
      frame_chunk_buffer.tme_ethernet_frame_chunk_bytes = frame;
      frame_chunk_buffer.tme_ethernet_frame_chunk_bytes_count
	= sizeof(frame);

      /* do the callout: */
      rc = (conn_eth == NULL
	    ? TME_OK
	    : ((*conn_eth->tme_ethernet_connection_read)
	       (conn_eth,
		&frame_id,
		&frame_chunk_buffer,
		TME_ETHERNET_READ_NEXT)));
      
      /* lock the mutex: */
      tme_mutex_lock(&tap->tme_bsd_tap_mutex);
      
      /* if the read was successful: */
      if (rc > 0) {

	/* check the size of the frame: */
	assert(rc <= sizeof(frame));

	/* do the write: */
	status = tme_thread_write(tap->tme_bsd_tap_fd, frame, rc);

	/* writes must succeed: */
	assert (status == rc);

	/* mark that we need to loop to callout to read more frames: */
	tap->tme_bsd_tap_callout_flags |= TME_BSD_TAP_CALLOUT_READ;
      }

      /* otherwise, the read failed.  convention dictates that we
	 forget that the connection was readable, which we already
	 have done by clearing the CALLOUT_READ flag: */
    }

  }
  
  /* put in any later callouts, and clear that callouts are running: */
  tap->tme_bsd_tap_callout_flags = later_callouts;
}

/* the TAP reader thread: */
static void
_tme_bsd_tap_th_reader(struct tme_bsd_tap *tap)
{
  ssize_t bytes;
  unsigned long sleep_usec;
  
  /* lock the mutex: */
  tme_mutex_lock(&tap->tme_bsd_tap_mutex);

  /* loop forever: */
  for (;;) {

    /* if the delay sleeping flag is set: */
    if (tap->tme_bsd_tap_delay_sleeping) {

      /* clear the delay sleeping flag: */
      tap->tme_bsd_tap_delay_sleeping = FALSE;
      
      /* call out that we can be read again: */
      _tme_bsd_tap_callout(tap, TME_BSD_TAP_CALLOUT_CTRL);
    }

    /* if a delay has been requested: */
    sleep_usec = tap->tme_bsd_tap_delay_sleep;
    if (sleep_usec > 0) {

      /* clear the delay sleep time: */
      tap->tme_bsd_tap_delay_sleep = 0;

      /* set the delay sleeping flag: */
      tap->tme_bsd_tap_delay_sleeping = TRUE;

      /* unlock our mutex: */
      tme_mutex_unlock(&tap->tme_bsd_tap_mutex);
      
      /* sleep for the delay sleep time: */
      tme_thread_sleep_yield(0, sleep_usec);
      
      /* lock our mutex: */
      tme_mutex_lock(&tap->tme_bsd_tap_mutex);
      
      continue;
    }

    /* if the buffer is not empty, wait until either it is,
       or we're asked to do a delay: */
    if (tap->tme_bsd_tap_buffer_in_bytes > 0) {
      tme_cond_wait_yield(&tap->tme_bsd_tap_cond_reader,
			  &tap->tme_bsd_tap_mutex);
      continue;
    }

    /* unlock the mutex: */
    tme_mutex_unlock(&tap->tme_bsd_tap_mutex);

    /* read the TAP interface: */
    tme_log(&tap->tme_bsd_tap_element->tme_element_log_handle, 1, TME_OK,
	    (&tap->tme_bsd_tap_element->tme_element_log_handle,
	     _("calling read")));
    bytes = 
      tme_thread_read_yield(tap->tme_bsd_tap_fd,
			    tap->tme_bsd_tap_buffer,
			    TME_ETHERNET_FRAME_MAX);

    /* lock the mutex: */
    tme_mutex_lock(&tap->tme_bsd_tap_mutex);

    /* if the read failed: */
    if (bytes <= 0) {
      tme_log(&tap->tme_bsd_tap_element->tme_element_log_handle, 1, errno,
	      (&tap->tme_bsd_tap_element->tme_element_log_handle,
	       _("failed to read packets")));
      continue;
    }

    /* the read succeeded: */
    tme_log(&tap->tme_bsd_tap_element->tme_element_log_handle, 1, TME_OK,
	    (&tap->tme_bsd_tap_element->tme_element_log_handle,
	     _("read %ld bytes of packets"), (long) bytes));
    tap->tme_bsd_tap_buffer_in_bytes = bytes;

    /* call out that we can be read again: */
    _tme_bsd_tap_callout(tap, TME_BSD_TAP_CALLOUT_CTRL);
  }
  /* NOTREACHED */
}

/* this is called when the ethernet configuration changes: */
static int
_tme_bsd_tap_config(struct tme_ethernet_connection *conn_eth, 
		    struct tme_ethernet_config *config)
{
  struct tme_bsd_tap *tap;
  int rc;

  /* recover our data structures: */
  tap = conn_eth->tme_ethernet_connection.tme_connection_element->tme_element_private;

  /* assume we will succeed: */
  rc = TME_OK;

  /* lock the mutex: */
  tme_mutex_lock(&tap->tme_bsd_tap_mutex);

  /* XXXXX: Nothing... */

  /* unlock the mutex: */
  tme_mutex_unlock(&tap->tme_bsd_tap_mutex);

  /* done: */
  return (rc);
}

/* this is called when control lines change: */
static int
_tme_bsd_tap_ctrl(struct tme_ethernet_connection *conn_eth, 
		  unsigned int ctrl)
{
  struct tme_bsd_tap *tap;
  int new_callouts;

  /* recover our data structures: */
  tap = conn_eth->tme_ethernet_connection.tme_connection_element->tme_element_private;

  /* assume that we won't need any new callouts: */
  new_callouts = 0;

  /* lock the mutex: */
  tme_mutex_lock(&tap->tme_bsd_tap_mutex);

  /* if this connection is readable, call out a read: */
  if (ctrl & TME_ETHERNET_CTRL_OK_READ) {
    new_callouts |= TME_BSD_TAP_CALLOUT_READ;
  }

  /* make any new callouts: */
  _tme_bsd_tap_callout(tap, new_callouts);

  /* unlock the mutex: */
  tme_mutex_unlock(&tap->tme_bsd_tap_mutex);

  return (TME_OK);
}

/* this is called to read a frame: */
static int
_tme_bsd_tap_read(struct tme_ethernet_connection *conn_eth, 
		  tme_ethernet_fid_t *_frame_id,
		  struct tme_ethernet_frame_chunk *frame_chunks,
		  unsigned int flags)
{
  struct tme_bsd_tap *tap;
  struct tme_ethernet_frame_chunk frame_chunk_buffer;
  const struct tme_ethernet_header *ethernet_header;
  const struct tme_net_arp_header *arp_header;
  const struct tme_net_ipv4_header *ipv4_header;
  tme_uint16_t ethertype;
  unsigned int count;
  int rc;

  /* recover our data structure: */
  tap = conn_eth->tme_ethernet_connection.tme_connection_element->tme_element_private;

  /* lock our mutex: */
  tme_mutex_lock(&tap->tme_bsd_tap_mutex);

  /* assume that we won't be able to return a packet: */
  rc = -ENOENT;

  /* loop until we have a good captured packet or until we 
     exhaust the buffer: */
  for (;;) {
    
    /* form the single frame chunk: */
    frame_chunk_buffer.tme_ethernet_frame_chunk_next = NULL;
    frame_chunk_buffer.tme_ethernet_frame_chunk_bytes = tap->tme_bsd_tap_buffer;
    frame_chunk_buffer.tme_ethernet_frame_chunk_bytes_count
      = tap->tme_bsd_tap_buffer_in_bytes;

    /* packets in a tme ethernet connection never have CRCs, so here
       we attempt to detect them and strip them off.

       unfortunately there's no general way to do this.  there's a
       chance that the last four bytes of an actual packet just
       happen to be the Ethernet CRC of all of the previous bytes in
       the packet, so we can't just strip off what looks like a
       valid CRC, plus the CRC calculation itself isn't cheap.

       the only way to do this well seems to be to look at the
       protocol.  if we can determine what the correct minimum size
       of the packet should be based on the protocol, and the size
       we got is four bytes more than that, assume that the last four
       bytes are a CRC and strip it off: */

    /* assume that we won't be able to figure out the correct minimum
       size of the packet: */
    count = 0;

    /* get the Ethernet header and packet type: */
    ethernet_header = (struct tme_ethernet_header *) tap->tme_bsd_tap_buffer;
    ethertype = ethernet_header->tme_ethernet_header_type[0];
    ethertype = (ethertype << 8) + ethernet_header->tme_ethernet_header_type[1];

    /* dispatch on the packet type: */
    switch (ethertype) {

      /* an ARP or RARP packet: */
    case TME_ETHERNET_TYPE_ARP:
    case TME_ETHERNET_TYPE_RARP:
      arp_header = (struct tme_net_arp_header *) (ethernet_header + 1);
      switch ((((tme_uint16_t) arp_header->tme_net_arp_header_opcode[0]) << 8)
	      + arp_header->tme_net_arp_header_opcode[1]) {
      case TME_NET_ARP_OPCODE_REQUEST:
      case TME_NET_ARP_OPCODE_REPLY:
      case TME_NET_ARP_OPCODE_REV_REQUEST:
      case TME_NET_ARP_OPCODE_REV_REPLY:
	count = (TME_ETHERNET_HEADER_SIZE
		 + sizeof(struct tme_net_arp_header)
		 + (2 * arp_header->tme_net_arp_header_hardware_length)
		 + (2 * arp_header->tme_net_arp_header_protocol_length));
      default:
	break;
      }
      break;

      /* an IPv4 packet: */
    case TME_ETHERNET_TYPE_IPV4:
      ipv4_header = (struct tme_net_ipv4_header *) (ethernet_header + 1);
      count = ipv4_header->tme_net_ipv4_header_length[0];
      count = (count << 8) + ipv4_header->tme_net_ipv4_header_length[1];
      count += TME_ETHERNET_HEADER_SIZE;
      break;

    default:
      break;
    }

    /* if we were able to figure out the correct minimum size of the
       packet, and the packet from BPF is exactly that minimum size
       plus the CRC size, set the length of the packet to be the
       correct minimum size.  NB that we can't let the packet become
       smaller than (TME_ETHERNET_FRAME_MIN - TME_ETHERNET_CRC_SIZE): */
    if (count != 0) {
      count = TME_MAX(count,
		      (TME_ETHERNET_FRAME_MIN
		       - TME_ETHERNET_CRC_SIZE));
      if (frame_chunk_buffer.tme_ethernet_frame_chunk_bytes_count
	  == (count + TME_ETHERNET_CRC_SIZE)) {
	frame_chunk_buffer.tme_ethernet_frame_chunk_bytes_count = count;
      }
    }

    /* copy out the frame: */
    count = tme_ethernet_chunks_copy(frame_chunks, &frame_chunk_buffer);

    /* if this is a not peek: */
    if (!(flags & TME_ETHERNET_READ_PEEK)) {

      tap->tme_bsd_tap_buffer_in_bytes = 0;
    }

    /* success: */
    rc = count;
    break;
  }

  /* if the buffer is empty, or if we failed to read a packet,
     wake up the reader: */
  if (tap->tme_bsd_tap_buffer_in_bytes <= 0
      || rc <= 0) {
    tme_cond_notify(&tap->tme_bsd_tap_cond_reader, TRUE);
  }

  /* unlock our mutex: */
  tme_mutex_unlock(&tap->tme_bsd_tap_mutex);

  /* done: */
  return (rc);
}

/* this makes a new Ethernet connection: */
static int
_tme_bsd_tap_connection_make(struct tme_connection *conn, unsigned int state)
{
  struct tme_bsd_tap *tap;
  struct tme_ethernet_connection *conn_eth;
  struct tme_ethernet_connection *conn_eth_other;

  /* recover our data structures: */
  tap = conn->tme_connection_element->tme_element_private;
  conn_eth = (struct tme_ethernet_connection *) conn;
  conn_eth_other = (struct tme_ethernet_connection *) conn->tme_connection_other;

  /* both sides must be Ethernet connections: */
  assert(conn->tme_connection_type == TME_CONNECTION_ETHERNET);
  assert(conn->tme_connection_other->tme_connection_type == TME_CONNECTION_ETHERNET);

  /* we're always set up to answer calls across the connection, so we
     only have to do work when the connection has gone full, namely
     taking the other side of the connection: */
  if (state == TME_CONNECTION_FULL) {

    /* lock our mutex: */
    tme_mutex_lock(&tap->tme_bsd_tap_mutex);

    /* save our connection: */
    tap->tme_bsd_tap_eth_connection = conn_eth_other;

    /* unlock our mutex: */
    tme_mutex_unlock(&tap->tme_bsd_tap_mutex);
  }

  return (TME_OK);
}

/* this breaks a connection: */
static int
_tme_bsd_tap_connection_break(struct tme_connection *conn, unsigned int state)
{
  abort();
}

/* this makes a new connection side for a TAP: */
static int
_tme_bsd_tap_connections_new(struct tme_element *element, 
			     const char * const *args, 
			     struct tme_connection **_conns,
			     char **_output)
{
  struct tme_bsd_tap *tap;
  struct tme_ethernet_connection *conn_eth;
  struct tme_connection *conn;

  /* recover our data structure: */
  tap = (struct tme_bsd_tap *) element->tme_element_private;

  /* if we already have an Ethernet connection, do nothing: */
  if (tap->tme_bsd_tap_eth_connection != NULL) {
    return (TME_OK);
  }

  /* allocate the new Ethernet connection: */
  conn_eth = tme_new0(struct tme_ethernet_connection, 1);
  conn = &conn_eth->tme_ethernet_connection;
  
  /* fill in the generic connection: */
  conn->tme_connection_next = *_conns;
  conn->tme_connection_type = TME_CONNECTION_ETHERNET;
  conn->tme_connection_score = tme_ethernet_connection_score;
  conn->tme_connection_make = _tme_bsd_tap_connection_make;
  conn->tme_connection_break = _tme_bsd_tap_connection_break;

  /* fill in the Ethernet connection: */
  conn_eth->tme_ethernet_connection_config = _tme_bsd_tap_config;
  conn_eth->tme_ethernet_connection_ctrl = _tme_bsd_tap_ctrl;
  conn_eth->tme_ethernet_connection_read = _tme_bsd_tap_read;

  /* return the connection side possibility: */
  *_conns = conn;

  /* done: */
  return (TME_OK);
}

/* the new TAP function: */
TME_ELEMENT_SUB_NEW_DECL(tme_host_bsd,tap) {
  struct tme_bsd_tap *tap;
  int tap_fd;
#define DEV_TAP_FORMAT "/dev/tap%d"
  char dev_tap_filename[sizeof(DEV_TAP_FORMAT) + (sizeof(int) * 3) + 1];
  int minor;
  int saved_errno;
  u_int tap_opt;
  const char *tap_name_user;
  int arg_i;
  int usage;
  
  /* check our arguments: */
  usage = 0;
  tap_name_user = NULL;
  arg_i = 1;
  for (;;) {

    /* the interface we're supposed to use: */
    if (TME_ARG_IS(args[arg_i + 0], "interface")
	&& args[arg_i + 1] != NULL) {
      tap_name_user = args[arg_i + 1];
      arg_i += 2;
    }

    /* if we ran out of arguments: */
    else if (args[arg_i + 0] == NULL) {
      break;
    }

    /* otherwise this is a bad argument: */
    else {
      tme_output_append_error(_output,
			      "%s %s", 
			      args[arg_i],
			      _("unexpected"));
      usage = TRUE;
      break;
    }
  }

  if (usage) {
    tme_output_append_error(_output,
			    "%s %s [ interface %s ] [ delay %s ]",
			    _("usage:"),
			    args[0],
			    _("INTERFACE"),
			    _("MICROSECONDS"));
    return (EINVAL);
  }

  /* loop trying to open a /dev/tap device: */
  for (minor = 0;; minor++) {
    
    /* form the name of the next device to try, then try opening
       it. if we succeed, we're done: */
    if (tap_name_user != NULL)
      sprintf(dev_tap_filename, "/dev/%s", tap_name_user);
    else
      sprintf(dev_tap_filename, DEV_TAP_FORMAT, minor);
    tme_log(&element->tme_element_log_handle, 1, TME_OK,
	    (&element->tme_element_log_handle,
	     "trying %s",
	     dev_tap_filename));
    if ((tap_fd = open(dev_tap_filename, O_RDWR)) >= 0) {
      tme_log(&element->tme_element_log_handle, 1, TME_OK,
	      (&element->tme_element_log_handle,
	       "opened %s",
	       dev_tap_filename));
      break;
    }

    /* we failed to open this device.  if this device was simply
       busy, loop: */
    saved_errno = errno;
    tme_log(&element->tme_element_log_handle, 1, saved_errno,
	    (&element->tme_element_log_handle, 
	     "%s", dev_tap_filename));
    if (saved_errno == EBUSY
	|| saved_errno == EACCES) {
      if (tap_name_user == NULL)
        continue;
    }

    /* otherwise, we have failed: */
    return (saved_errno);
  }

  /* put the TAP device into non-blocking I/O mode: */
  tap_opt = TRUE;
  if (ioctl(tap_fd, FIONBIO, &tap_opt) < 0) {
    tme_log(&element->tme_element_log_handle, 1, errno,
           (&element->tme_element_log_handle,
            _("failed to put %s into non-blocking I/O mode"),
            dev_tap_filename));
    saved_errno = errno;
    close(tap_fd);
    errno = saved_errno;
    return (errno);
  }

  /* start our data structure: */
  tap = tme_new0(struct tme_bsd_tap, 1);
  tap->tme_bsd_tap_element = element;
  tap->tme_bsd_tap_fd = tap_fd;
  tap->tme_bsd_tap_buffer = tme_new(tme_uint8_t, TME_ETHERNET_FRAME_MAX);

  /* start the threads: */
  tme_mutex_init(&tap->tme_bsd_tap_mutex);
  tme_cond_init(&tap->tme_bsd_tap_cond_reader);
  tme_thread_create((tme_thread_t) _tme_bsd_tap_th_reader, tap);

  /* fill the element: */
  element->tme_element_private = tap;
  element->tme_element_connections_new = _tme_bsd_tap_connections_new;

  return (TME_OK);
}
