# $NetBSD: Makefile,v 1.33 2009/08/11 14:35:15 drochner Exp $
#

DISTNAME=	autotrace-0.31.1
PKGREVISION=	9
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	Convert bitmap to vector graphics

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	autotrace.pc.in
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
