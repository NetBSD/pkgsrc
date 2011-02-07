# $NetBSD: Makefile,v 1.42 2011/02/07 00:37:10 wiz Exp $
#

DISTNAME=	autotrace-0.31.1
PKGREVISION=	17
CATEGORIES=	graphics cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autotrace/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://autotrace.sourceforge.net/
COMMENT=	Convert bitmap to vector graphics
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	autotrace.pc.in
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
