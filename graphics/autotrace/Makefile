# $NetBSD: Makefile,v 1.16 2004/01/03 18:49:41 reed Exp $
#

DISTNAME=	autotrace-0.31.1
PKGREVISION=	2
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	Convert bitmap to vector graphics

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE=	${WRKSRC}/autotrace.pc.in

.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
