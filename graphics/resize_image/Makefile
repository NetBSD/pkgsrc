# $NetBSD: Makefile,v 1.1.1.1 2003/09/10 21:44:46 itojun Exp $
#

DISTNAME=	resize_image-0.6
CATEGORIES=	graphics
MASTER_SITES=	http://lab.erasme.org/resize_image/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lab.erasme.org/resize_image/
COMMENT=	Fast image resizing tool

USE_GMAKE=	YES
CFLAGS+=	-DUNIX

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resize_image ${PREFIX}/bin

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
