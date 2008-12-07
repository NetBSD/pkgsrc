# $NetBSD: Makefile,v 1.15 2008/12/07 12:32:27 bjs Exp $
#

DISTNAME=	usbutil-0.5
PKGREVISION=	3
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
