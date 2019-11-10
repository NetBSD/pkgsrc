# $NetBSD: Makefile,v 1.27 2019/11/10 11:19:50 nia Exp $

DISTNAME=	babl-0.1.72
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/babl/0.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dwith-docs=false
MESON_ARGS+=	-Denable-gir=false

PKGCONFIG_OVERRIDE+=	babl.pc.in

PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script,babl.map

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
