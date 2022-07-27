# $NetBSD: Makefile,v 1.183 2022/07/27 08:40:58 adam Exp $

DISTNAME=	wesnoth-1.16.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		bash msgfmt perl:run pkg-config
# detects history.h, but does not link against libhistory
CMAKE_ARGS+=		-DENABLE_HISTORY=OFF
# if OPT is set, -O3 will not be added
CMAKE_ARGS+=		-DOPT="${DBG}"

CFLAGS.Darwin=		-framework Cocoa

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

REPLACE_BASH+=		data/tools/unit_tree/update-wmlunits

REPLACE_PYTHON+=	data/tools/GUI.pyw
REPLACE_PYTHON+=	data/tools/*.py
REPLACE_PYTHON+=	data/tools/wesnoth/*.py
REPLACE_PYTHON+=	data/tools/wml*
REPLACE_PYTHON+=	data/tools/about_cfg_to_wiki
REPLACE_PYTHON+=	data/tools/addon_manager/html.py
REPLACE_PYTHON+=	data/tools/extractbindings
REPLACE_PYTHON+=	data/tools/imgcheck
REPLACE_PYTHON+=	data/tools/journeylifter
REPLACE_PYTHON+=	data/tools/rmtrans/rmtrans.py
REPLACE_PYTHON+=	data/tools/steam-changelog
REPLACE_PYTHON+=	data/tools/tmx_trackplacer
REPLACE_PYTHON+=	data/tools/trackplacer
REPLACE_PYTHON+=	data/tools/trackviewer.pyw
REPLACE_PYTHON+=	data/tools/unit_tree/helpers.py
REPLACE_PYTHON+=	data/tools/unit_tree/TeamColorizer
REPLACE_PYTHON+=	data/tools/unit_tree/overview.py
REPLACE_PYTHON+=	data/tools/wesnoth/trackplacer3/datatypes.py
REPLACE_PYTHON+=	data/tools/wesnoth_addon_manager
REPLACE_PYTHON+=	utils/ai_test/*.py
REPLACE_PYTHON+=	utils/*.py

PLIST_VARS+=		icons

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
PLIST.icons=		yes
.endif

LDFLAGS.SunOS+=		-lintl -lsocket

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.14.8
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
