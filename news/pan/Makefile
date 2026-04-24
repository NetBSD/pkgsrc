# $NetBSD: Makefile,v 1.165 2026/04/24 18:16:14 rhialto Exp $

PKGNAME=		pan-0.165
CATEGORIES=		news
TAG=			${PKGNAME_NOREV:S/pan-/v/} # e.g. v0.151
MASTER_SITES=		https://gitlab.gnome.org/GNOME/pan/-/archive/${TAG}/
EXTRACT_SUFX=		.tar.bz2
DISTNAME=		pan-${TAG}

MAINTAINER=		rhialto@NetBSD.org
HOMEPAGE=		https://gitlab.gnome.org/GNOME/pan
COMMENT=		Newsreader for GTK3
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools
TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

USE_TOOLS+=		gmake msgfmt perl pkg-config itstool
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux"
LIBS+=			-lcompat
.endif

CMAKE_CONFIGURE_ARGS+=	-DENABLE_MANUAL=1
CMAKE_CONFIGURE_ARGS+=	-DWANT_GKR=0
CMAKE_CONFIGURE_ARGS+=	-DWANT_GMIME_CRYPTO=1
CMAKE_CONFIGURE_ARGS+=	-DWANT_GNUTLS=1
CMAKE_CONFIGURE_ARGS+=	-DWANT_GSPELL=1
CMAKE_CONFIGURE_ARGS+=	-DWANT_NOTIFY=0
CMAKE_CONFIGURE_ARGS+=	-DWANT_WEBKIT=0

LDFLAGS.SunOS+=	-lsocket

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
