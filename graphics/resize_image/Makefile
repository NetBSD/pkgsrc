# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:59 jlam Exp $
#

DISTNAME=	resize_image-0.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://lab.erasme.org/resize_image/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lab.erasme.org/resize_image/
COMMENT=	Fast image resizing tool

USE_TOOLS+=	gmake
CFLAGS+=	-DUNIX

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resize_image ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
