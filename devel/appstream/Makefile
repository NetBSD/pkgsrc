# $NetBSD: Makefile,v 1.8 2024/05/16 06:14:44 wiz Exp $

DISTNAME=	appstream-1.0.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ximion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ximion/appstream
COMMENT=	Tools and libraries to work with AppStream metadata
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		itstool pkg-config

MESON_ARGS+=	-Dapidocs=false
MESON_ARGS+=	-Dsystemd=false
# for running a tool during the build
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src
# for Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/src

PKGCONFIG_OVERRIDE+=		output/meson-private/appstream.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

# Hard-coded path to /usr/include for libstemmer.h.
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	meson.build
SUBST_SED.paths=	-e 's,/usr/include,${PREFIX}/include,g'

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../textproc/libstemmer/buildlink3.mk"
.include "../../textproc/libxmlb/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
