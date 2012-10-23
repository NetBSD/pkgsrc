# $NetBSD: Makefile,v 1.18 2012/10/23 19:51:28 asau Exp $
#

DISTNAME=	usbutil-0.5
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	lennart@augustsson.net
COMMENT=	USB developer utilities

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/usbgen.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/usbgen.8

.include "../../mk/bsd.pkg.mk"
