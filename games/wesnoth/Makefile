# $NetBSD: Makefile,v 1.68 2012/01/09 02:54:26 obache Exp $

DISTNAME=	wesnoth-1.8.6
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

PKG_DESTDIR_SUPPORT=	user-destdir

#USE_CMAKE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		aclocal autoconf autoheader automake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}

UNLIMIT_RESOURCES+=	datasize

REPLACE_PERL+=		utils/wesnothd.pl
USE_TOOLS+=		perl:run msgfmt

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-build
SUBST_FILES.python+=	data/tools/expand-terrain-macros.py
SUBST_FILES.python+=	data/tools/scoutDefault.py
SUBST_FILES.python+=	data/tools/wesnoth/wescamp.py
SUBST_FILES.python+=	data/tools/wesnoth/wmldata.py
SUBST_FILES.python+=	data/tools/wesnoth/wmlparser.py
SUBST_FILES.python+=	utils/ai_test/ai_test.py
SUBST_FILES.python+=	utils/mediawiki.py
SUBST_FILES.python+=	utils/pofix.py
SUBST_FILES.python+=	utils/test_libsvn.py
SUBST_FILES.python+=	utils/unused_functions.py
SUBST_FILES.python+=	utils/wiki_grabber.py
SUBST_MESSAGE.python=	Fixing path to python.
# Best we can do without pulling in a python dependency.
SUBST_SED.python+=	-e 's,WPY,${PREFIX}/bin/python2.6,'
SUBST_SED.python+=	-e 's,/bin/env.*python,${PREFIX}/bin/python2.6,'
SUBST_SED.python+=	-e 's,/usr/bin/python,${PREFIX}/bin/python2.6,'

REPLACE_RUBY=		data/tools/terrain2wiki.rb
.include "../../lang/ruby/replace.mk"

REPLACE_SH+=		data/tools/castle-cutter/mk-castle.sh
REPLACE_SH+=		data/tools/castle-cutter/mk-all-castles.sh

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.*)
USE_TOOLS+=		gmake
.endif

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal -I m4; autoheader; automake -a --foreign -i; autoconf

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
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
