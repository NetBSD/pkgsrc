# $NetBSD: Makefile,v 1.22 2014/08/22 11:24:36 wiz Exp $

DISTNAME=	tango-icon-theme-0.8.90
PKGREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	http://tango.freedesktop.org/releases/

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://tango.freedesktop.org/Tango_Desktop_Project
COMMENT=	Tango desktop project icon theme
LICENSE=	public-domain

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt

BUILDLINK_DEPMETHOD.ImageMagick=	build
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90


.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
