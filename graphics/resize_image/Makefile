# $NetBSD: Makefile,v 1.7 2004/10/03 00:14:57 tv Exp $
#

DISTNAME=	resize_image-0.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://lab.erasme.org/resize_image/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lab.erasme.org/resize_image/
COMMENT=	Fast image resizing tool

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
CFLAGS+=	-DUNIX

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resize_image ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
