# $NetBSD: Makefile,v 1.5 2004/01/24 15:46:44 grant Exp $
#

DISTNAME=	resize_image-0.6
CATEGORIES=	graphics
MASTER_SITES=	http://lab.erasme.org/resize_image/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lab.erasme.org/resize_image/
COMMENT=	Fast image resizing tool

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
CFLAGS+=	-DUNIX

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resize_image ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
