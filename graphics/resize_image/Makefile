# $NetBSD: Makefile,v 1.4 2004/01/10 19:08:25 kristerw Exp $
#

DISTNAME=	resize_image-0.6
CATEGORIES=	graphics
MASTER_SITES=	http://lab.erasme.org/resize_image/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lab.erasme.org/resize_image/
COMMENT=	Fast image resizing tool

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
CFLAGS+=	-DUNIX

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resize_image ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
