# New ports collection makefile for:    zip (without encryption)
# http://infozip.cdrom.com/pub/infozip/
#
# Version required:     2.1
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.3 1997/11/01 01:49:08 hubertf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp 
#

DISTNAME=       zip21
PKGNAME=        zip-2.1
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/src/
EXTRACT_SUFX=   .zip

MAINTAINER=     ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -oq
NO_WRKSUBDIR=   yes
MAKEFILE=       unix/Makefile
MAKE_FLAGS=     LOCAL_ZIP="${CFLAGS}" -f
ALL_TARGET=     generic
MAN1=           zip.1

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

post-install:
.if defined(MANZ)
	ln ${PREFIX}/man/man1/zip.1.gz	${PREFIX}/man/man1/zipcloak.1.gz
	ln ${PREFIX}/man/man1/zip.1.gz	${PREFIX}/man/man1/zipnote.1.gz
	ln ${PREFIX}/man/man1/zip.1.gz	${PREFIX}/man/man1/zipsplit.1.gz
.else
	ln ${PREFIX}/man/man1/zip.1	${PREFIX}/man/man1/zipcloak.1
	ln ${PREFIX}/man/man1/zip.1	${PREFIX}/man/man1/zipnote.1
	ln ${PREFIX}/man/man1/zip.1	${PREFIX}/man/man1/zipsplit.1
.endif

.include <bsd.port.mk>
