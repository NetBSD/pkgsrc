# $NetBSD: Makefile,v 1.52 2009/06/08 15:15:50 wiz Exp $

DISTNAME=	wesnoth-1.6.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
USE_DIRS=		xdg-1.4
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

UNLIMIT_RESOURCES+=	datasize

REPLACE_PERL+=		utils/webtgz.pl
REPLACE_PERL+=		utils/weblist.pl
REPLACE_PERL+=		utils/wesnothd.pl
REPLACE_PERL+=		utils/unit.pl
REPLACE_PERL+=		utils/mp-lobby-logger.pl
USE_TOOLS+=		perl:run msgfmt

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-build
SUBST_FILES.python+=	data/tools/scoutDefault.py
SUBST_FILES.python+=	data/tools/expand-terrain-macros.py
SUBST_FILES.python+=	data/tools/wesnoth/wescamp.py
SUBST_FILES.python+=	data/tools/wesnoth/wmlparser.py
SUBST_FILES.python+=	data/tools/wesnoth/wmldata.py
SUBST_FILES.python+=	utils/unused_functions.py
SUBST_FILES.python+=	utils/test_libsvn.py
SUBST_FILES.python+=	utils/pofix.py
SUBST_FILES.python+=	utils/wiki_grabber.py
SUBST_FILES.python+=	utils/mediawiki.py
SUBST_MESSAGE.python=	Fixing path to python.
# Best we can do without pulling in a python dependency.
SUBST_SED.python+=	-e 's,WPY,${PREFIX}/bin/python2.5,'
SUBST_SED.python+=	-e 's,/bin/env.*python,${PREFIX}/bin/python2.5,'
SUBST_SED.python+=	-e 's,/usr/bin/python,${PREFIX}/bin/python2.5,'

REPLACE_RUBY=		data/tools/terrain2wiki.rb
REPLACE_RUBY+=		utils/stats/website/tools/wesnoth_process_dbase.rb
REPLACE_RUBY+=		utils/stats/website/tools/wmlnode.rb
REPLACE_RUBY+=		utils/stats/website/tools/sqlitedb2wml.rb
REPLACE_RUBY+=		utils/stats/website/tools/wmlparser.rb
REPLACE_RUBY+=		utils/stats/website/tools/sqlite2mysql.rb
REPLACE_RUBY+=		utils/stats/website/public/dispatch.rb
.include "../../lang/ruby/replace.mk"

REPLACE_SH+=		data/tools/castle-cutter/mk-castle.sh
REPLACE_SH+=		data/tools/castle-cutter/mk-all-castles.sh

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
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
