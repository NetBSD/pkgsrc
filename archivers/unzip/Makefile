# New ports collection makefile for:    unzip
# Version required:     5.3.2
# Date created:         17 October 1994
# Whom:                 jmz
#
# $NetBSD: Makefile,v 1.5 1998/03/07 21:24:05 hubertf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/06/19 05:30:04 ache Exp 
#

DISTNAME=       unzip-5.32
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/src/
DISTFILES=      unzip532.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

MAKEFILE=       unix/Makefile
ALL_TARGET=     bsd
MAKE_FLAGS=     LOCAL_UNZIP="${CFLAGS} -DUSE_UNSHRINK" -f
MAN1=           funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	ln -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && \
		${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/unix && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && \
		${INSTALL_DATA} README WHERE COPYING ${PREFIX}/share/doc/unzip

.include <bsd.port.mk>
