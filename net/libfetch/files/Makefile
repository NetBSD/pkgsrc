# $NetBSD: Makefile,v 1.9 2025/02/10 03:52:32 pho Exp $

LIB=		fetch
SRCS=		fetch.c common.c ftp.c http.c file.c
DPSRCS= 	ftperr.h httperr.h
INCS=		fetch.h
MAN=		fetch.3
PKGCONFIGS=	fetch.pc
CLEANFILES=	ftperr.h httperr.h
MKLINT=		no
MKPIC=		no
MKPROFILE=	no

.include <bsd.own.mk>

CPPFLAGS+=	-I.
CPPFLAGS+=	-D_LARGEFILE_SOURCE -D_LARGE_FILES -D_FILE_OFFSET_BITS=64

FETCH_WITH_INET6?=	no
FETCH_WITH_OPENSSL?=	no

.if !empty(FETCH_WITH_INET6:M[yY][eE][sS])
CPPFLAGS+=	-DINET6
.endif

.if !empty(FETCH_WITH_OPENSSL:M[yY][eE][sS])
CPPFLAGS+=	-DWITH_SSL
LDADD=		-lssl -lcrypto
_PC_DEPS+=	libssl libcrypto
.endif

CPPFLAGS+=	-DFTP_COMBINE_CWDS

WARNS?=		4

ftp.o: ftperr.h
http.o: httperr.h

ftperr.h: ${.CURDIR}/ftp.errors ${.CURDIR}/Makefile ${.CURDIR}/errlist.sh
	sh ${.CURDIR}/errlist.sh ftp_errlist FTP \
	    ${.CURDIR}/ftp.errors > ${.TARGET}

httperr.h: ${.CURDIR}/http.errors ${.CURDIR}/Makefile ${.CURDIR}/errlist.sh
	sh ${.CURDIR}/errlist.sh http_errlist HTTP \
	    ${.CURDIR}/http.errors > ${.TARGET}

.if defined(PKGCONFIGS)
.  for f in ${PKGCONFIGS}
all:		${f}
FILES+=		${f}
CLEANFILES+=	${f}
FILESDIR_${f}=	${LIBDIR}/pkgconfig
.  endfor
.SUFFIXES:	.pc.in .pc
.pc.in.pc: ${.CURDIR}/Makefile
	${SED} \
		-e "s,@libdir@,${LIBDIR}," \
		-e "s,@includedir@,${INCSDIR}," \
		-e "s,@requires-private@,${_PC_DEPS}," \
		< ${.IMPSRC} > ${.TARGET}
.endif

.include <bsd.lib.mk>
.include <bsd.files.mk>
