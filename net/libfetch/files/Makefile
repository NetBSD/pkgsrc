# $NetBSD

LIB=		fetch
SRCS=		fetch.c common.c ftp.c http.c file.c ftperr.h httperr.h
INCS=		fetch.h
MAN=		fetch.3
CLEANFILES=	ftperr.h httperr.h
MKLINT=		no
MKPIC=		no
MKPROFILE=	no

.include <bsd.own.mk>

CPPFLAGS+=	-I.

FETCH_WITH_INET6?=	no
FETCH_WITH_OPENSSL?=	no

.if !empty(FETCH_WITH_INET6:M[yY][eE][sS])
CPPFLAGS+=	-DINET6
.endif

.if !empty(FETCH_WITH_OPENSSL:M[yY][eE][sS])
CPPFLAGS+=	-DWITH_SSL
LDADD=		-lssl -lcrypto
.endif

CPPFLAGS+=	-DFTP_COMBINE_CWDS

WARNS?=		4

ftperr.h: ${.CURDIR}/ftp.errors ${.CURDIR}/Makefile ${.CURDIR}/errlist.awk
	awk -v variable=ftp_errlist -v protocol=FTP \
	    -f ${.CURDIR}/errlist.awk ${.CURDIR}/ftp.errors > ${.TARGET}

httperr.h: ${.CURDIR}/http.errors ${.CURDIR}/Makefile ${.CURDIR}/errlist.awk
	awk -v variable=http_errlist -v protocol=HTTP \
	    -f ${.CURDIR}/errlist.awk ${.CURDIR}/http.errors > ${.TARGET}

.include <bsd.lib.mk>
