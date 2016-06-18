# $NetBSD: Makefile,v 1.118 2016/06/18 21:18:16 leot Exp $

DISTNAME=	wesnoth-1.12.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_CMAKE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_TOOLS+=		perl:run msgfmt
USE_TOOLS+=		bash

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

REPLACE_PERL+=		utils/wesnothd.pl

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	cmake/FindFriBiDi.cmake
SUBST_MESSAGE.prefix=	Fixing search path.
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 1.10.6
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
REPLACE_PYTHON+=	data/tools/trackplacer
REPLACE_PYTHON+=	data/tools/unit_tree/helpers.py
REPLACE_PYTHON+=	data/tools/wesnoth_addon_manager
REPLACE_PYTHON+=	data/tools/wesnoth_addon_manager/html.py
REPLACE_PYTHON+=	data/tools/wesnoth/campaignserver_client.py
REPLACE_PYTHON+=	data/tools/unit_tree/TeamColorizer
REPLACE_PYTHON+=	data/tools/unit_tree/overview.py
REPLACE_PYTHON+=	utils/ai_test/*.py
REPLACE_PYTHON+=	utils/*.py

REPLACE_BASH+=		data/tools/castle-cutter/mk-all-castles.sh
REPLACE_BASH+=		data/tools/castle-cutter/mk-castle.sh
REPLACE_BASH+=		data/tools/unit_tree/update-wmlunits

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.*)
USE_TOOLS+=		gmake
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

PLIST_VARS+=		icons

.if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
PLIST.icons=		yes
.endif

LDFLAGS.SunOS+=		-lintl -lsocket

# To avoid *.orig files (after patch) installed
post-patch:
	(cd ${WRKSRC}; \
	${RM} data/tools/addon_manager/html.py.orig; \
	${RM} data/tools/castle-cutter/mk-all-castles.sh.orig; \
	${RM} data/tools/unit_tree/helpers.py.orig; \
	${RM} data/tools/wesnoth/campaignserver_client.py.orig;\
	)

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb3
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=		SDL>=1.2.7
.include "../../devel/SDL/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL_ttf+=		SDL_ttf>=2.0.8
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.14.8
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
