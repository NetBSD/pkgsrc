# $NetBSD: Makefile,v 1.22 2004/12/28 23:18:15 reed Exp $
#

DISTNAME=	autotrace-0.31.1
PKGREVISION=	4
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	Convert bitmap to vector graphics

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	autotrace.pc.in

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
