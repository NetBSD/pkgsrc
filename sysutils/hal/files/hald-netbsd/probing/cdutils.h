/***************************************************************************
 *
 * cdutils.h : definitions for CD/DVD utilities
 *
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifndef CDUTILS_H
#define CDUTILS_H

#include <sys/types.h>
#include <sys/dkio.h>
#include <sys/cdio.h>
#include <sys/scsiio.h>
#include <stdbool.h>
#include <stdint.h>

enum {
	CDUTIL_WALK_CONTINUE,
	CDUTIL_WALK_STOP
};

typedef struct intlist {
	int	val;
	struct intlist *next;
} intlist_t;

typedef struct disc_info {
	int	disc_status;
	int	erasable;
	uint64_t capacity;
} disc_info_t;

#define	min(a, b)	((a) < (b) ? (a) : (b))
#define	max(a, b)	((a) > (b) ? (a) : (b))

bool		scsi_command(int fd, void *cmd, size_t cmdlen, void *data,
			size_t datalen, int timeout, int flags);
int		mode_sense(int fd, u_char pc, int dbd, int page_len,
			u_char *buffer);
int		get_mode_page(int fd, int page_no, int pc, int buf_len,
			u_char *buffer, int *plen);
int		get_configuration(int fd, uint16_t feature, int bufsize,
			u_char *buf);
bool		get_current_profile(int fd, int *profile);
void		walk_profiles(int fd, int (*f)(void *, int, bool), void *);
void		get_read_write_speeds(int fd, int *read_speed, int *write_speed,
			intlist_t **wspeeds, int *n_wspeeds, intlist_t **wspeeds_mem);
bool		get_disc_info(int fd, disc_info_t *);
bool		read_format_capacity(int fd, uint64_t *capacity);
bool		get_media_info(int fd, uint64_t *capacity);
bool		get_disc_capacity_for_profile(int fd, int profile,
			uint64_t *capacity);
bool		read_toc(int fd, int format, int trackno, int buflen,
			u_char *buf);

#endif /* CDUTILS_H */
