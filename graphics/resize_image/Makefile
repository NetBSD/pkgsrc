# $NetBSD: Makefile,v 1.16 2010/12/23 11:44:44 dsainty Exp $
#

DISTNAME=	resize_image-0.6
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://lab.erasme.org/resize_image/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lab.erasme.org/resize_image/
COMMENT=	Fast image resizing tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
CFLAGS+=	-DUNIX

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resize_image ${DESTDIR}${PREFIX}/bin

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
