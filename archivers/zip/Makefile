# New ports collection makefile for:    zip (without encryption)
# http://infozip.cdrom.com/pub/infozip/
#
# Version required:     2.2
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.4 1998/01/15 13:53:58 agc Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp 
#

DISTNAME=       zip-2.2
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/src/
DISTFILES=	zip22.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

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
	ln -fs ${PREFIX}/man/man1/zip.1.gz	${PREFIX}/man/man1/zipcloak.1.gz
	ln -fs ${PREFIX}/man/man1/zip.1.gz	${PREFIX}/man/man1/zipnote.1.gz
	ln -fs ${PREFIX}/man/man1/zip.1.gz	${PREFIX}/man/man1/zipsplit.1.gz
.else
	ln -fs ${PREFIX}/man/man1/zip.1	${PREFIX}/man/man1/zipcloak.1
	ln -fs ${PREFIX}/man/man1/zip.1	${PREFIX}/man/man1/zipnote.1
	ln -fs ${PREFIX}/man/man1/zip.1	${PREFIX}/man/man1/zipsplit.1
.endif

.include <bsd.port.mk>
