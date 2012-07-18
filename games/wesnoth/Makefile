# $NetBSD: Makefile,v 1.76 2012/07/18 06:37:40 adam Exp $

DISTNAME=	wesnoth-1.10.3
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

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-build
SUBST_FILES.python+=	data/tools/*.py
SUBST_FILES.python+=	data/tools/wesnoth/*.py
SUBST_FILES.python+=	data/tools/wml*
SUBST_FILES.python+=	data/tools/about_cfg_to_wiki
SUBST_FILES.python+=	data/tools/extractbindings
SUBST_FILES.python+=	data/tools/imgcheck
SUBST_FILES.python+=	data/tools/journeylifter
SUBST_FILES.python+=	data/tools/trackplacer
SUBST_FILES.python+=	data/tools/wesnoth_addon_manager
SUBST_FILES.python+=	data/tools/unit_tree/TeamColorizer
SUBST_FILES.python+=	data/tools/unit_tree/overview.py
SUBST_FILES.python+=	utils/ai_test/*.py
SUBST_FILES.python+=	utils/*.py
SUBST_MESSAGE.python=	Fixing path to python.
# Best we can do without pulling in Python dependency
SUBST_SED.python+=	-e 's,WPY,${PREFIX}/bin/python2.7,'
SUBST_SED.python+=	-e 's,/usr/bin/env.*python,${PREFIX}/bin/python2.7,'
SUBST_SED.python+=	-e 's,/usr/bin/python,${PREFIX}/bin/python2.7,'

REPLACE_RUBY=		data/tools/terrain2wiki.rb
.include "../../lang/ruby/replace.mk"

REPLACE_SH+=		data/tools/castle-cutter/mk-castle.sh
REPLACE_SH+=		data/tools/castle-cutter/mk-all-castles.sh

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
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
