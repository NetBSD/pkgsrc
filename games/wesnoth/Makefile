# $NetBSD: Makefile,v 1.140 2018/11/14 22:21:32 kleink Exp $

DISTNAME=	wesnoth-1.14.5
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
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
REPLACE_PYTHON+=	data/tools/trackplacer
REPLACE_PYTHON+=	data/tools/unit_tree/helpers.py
REPLACE_PYTHON+=	data/tools/unit_tree/TeamColorizer
REPLACE_PYTHON+=	data/tools/unit_tree/overview.py
REPLACE_PYTHON+=	data/tools/wesnoth_addon_manager
REPLACE_PYTHON+=	utils/ai_test/*.py
REPLACE_PYTHON+=	utils/*.py

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.*)
USE_TOOLS+=		gmake
.endif

PLIST_VARS+=		icons

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
.include "../../mk/bsd.pkg.mk"
