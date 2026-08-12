# $NetBSD: Makefile,v 1.53 2026/08/12 12:51:34 wiz Exp $

DISTNAME=	lv2-1.18.10
PKGREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	https://lv2plug.in/spec/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lv2plug.in/
COMMENT=	Open standard for audio plugins, used by hundreds of plugins
LICENSE=	isc

PLIST_SRC+=	${PLIST_SRC_DFLT}

USE_TOOLS+=	pkg-config

# header-only-library, so not needed
#PKGCONFIG_OVERRIDE+=		output/meson-private/lv2.pc
#PKGCONFIG_OVERRIDE_STAGE=	post-configure

REPLACE_PYTHON+=	lv2specgen/lv2specgen.py
REPLACE_PYTHON+=	scripts/lv2_build_index.py

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
