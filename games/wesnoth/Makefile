# $NetBSD: Makefile,v 1.81.2.1 2012/10/03 12:07:49 spz Exp $

DISTNAME=	wesnoth-1.10.4
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		aclocal autoconf autoheader automake pkg-config
USE_TOOLS+=		perl:run msgfmt

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

REPLACE_PERL+=		utils/wesnothd.pl

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	cmake/FindFriBiDi.cmake
SUBST_MESSAGE.prefix=	Fixing search path.
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'

REPLACE_PYTHON+=	data/tools/*.py
REPLACE_PYTHON+=	data/tools/wesnoth/*.py
REPLACE_PYTHON+=	data/tools/wml*
REPLACE_PYTHON+=	data/tools/about_cfg_to_wiki
REPLACE_PYTHON+=	data/tools/extractbindings
REPLACE_PYTHON+=	data/tools/imgcheck
REPLACE_PYTHON+=	data/tools/journeylifter
REPLACE_PYTHON+=	data/tools/trackplacer
REPLACE_PYTHON+=	data/tools/wesnoth_addon_manager
REPLACE_PYTHON+=	data/tools/unit_tree/TeamColorizer
REPLACE_PYTHON+=	data/tools/unit_tree/overview.py
REPLACE_PYTHON+=	utils/ai_test/*.py
REPLACE_PYTHON+=	utils/*.py

REPLACE_RUBY=		data/tools/terrain2wiki.rb
.include "../../lang/ruby/replace.mk"

REPLACE_SH+=		data/tools/castle-cutter/mk-castle.sh
REPLACE_SH+=		data/tools/castle-cutter/mk-all-castles.sh

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.*)
USE_TOOLS+=		gmake
.endif

PLIST_VARS+=		icons

.if ${OPSYS} != "Darwin"
PLIST.icons=		yes
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.endif

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb3
.include "../../audio/SDL_mixer/buildlink3.mk"
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
.include "../../mk/bsd.pkg.mk"
