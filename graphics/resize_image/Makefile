# $NetBSD: Makefile,v 1.20 2025/04/24 14:14:38 wiz Exp $
#

DISTNAME=	resize_image-0.6
PKGREVISION=	6
CATEGORIES=	graphics
#MASTER_SITES=	http://lab.erasme.org/resize_image/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://lab.erasme.org/resize_image/
COMMENT=	Fast image resizing tool

USE_TOOLS+=	gmake
CFLAGS+=	-DUNIX

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resize_image ${DESTDIR}${PREFIX}/bin

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
