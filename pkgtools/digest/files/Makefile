#	$NetBSD: Makefile,v 1.9 2002/06/21 15:26:08 abs Exp $

# When adding new digest algorithms, please use rmd160 as the template,
# and bump the version definition in the package Makefile

PROG= digest
SRCS= digest.c
CPPFLAGS+= -I${.CURDIR} -DVERSION="${VERSION}"
WARNS= 2

SRCS+= rmd160.c rmd160hl.c

SRCS+= sha1.c sha1hl.c

.if !exists(/usr/include/sha2.h)
SRCS+= sha2.c sha2hl.c
.endif

.if !exists(/usr/include/md5.h) || ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
SRCS+= md5c.c md5hl.c
.endif

# use definition for correct endian.h header file
.if exists(/usr/include/sys/endian.h)
CPPFLAGS+= -DHAVE_SYS_ENDIAN_H_
.endif
.if exists(/usr/include/machine/endian.h)
CPPFLAGS+= -DHAVE_MACHINE_ENDIAN_H_
.endif

.if ${OPSYS} == SunOS || ${OPSYS} == "Linux"
MKCATPAGES=	no
.elif ${OPSYS} != "Darwin"
LDSTATIC?=      -static
.endif

.include <bsd.prog.mk>
