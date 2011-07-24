# $NetBSD: Makefile,v 1.17 2011/07/24 18:00:06 jmcneill Exp $
#

DISTNAME=	usbutil-0.5
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	lennart@augustsson.net
COMMENT=	USB developer utilities

PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/usbgen.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/usbgen.8

.include "../../mk/bsd.pkg.mk"
