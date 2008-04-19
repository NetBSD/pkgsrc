# $NetBSD: Makefile,v 1.43 2008/04/19 09:35:24 wiz Exp $

DISTNAME=	wesnoth-1.4.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
USE_DIRS=		xdg-1.4
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

UNLIMIT_RESOURCES+=	datasize

REPLACE_PERL+=		utils/wmlxgettext
REPLACE_PERL+=		data/tools/unit_tree/units.pl
REPLACE_PERL+=		data/tools/unit_tree/TeamColorizer.pl
REPLACE_PERL+=		data/tools/TeamColorizer.pl
USE_TOOLS+=		perl:run msgfmt

REPLACE_PYTHON=		data/ais/documentation.py
SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-build
SUBST_FILES.python=	data/ais/sample.py
SUBST_FILES.python+=	data/ais/bruteforce.py
SUBST_FILES.python+=	data/campaigns/Descent_Into_Darkness/ais/kamikaze.py
SUBST_FILES.python+=	data/tools/scoutDefault.py
SUBST_MESSAGE.python=	Fixing path to python.
# Best we can do without pulling in a python dependency.
SUBST_SED.python+=	-e 's,WPY,${PREFIX}/bin/python2.4,'
SUBST_SED.python+=	-e 's,/bin/env.*python,${PREFIX}/bin/python2.4,'

REPLACE_RUBY=		data/tools/terrain2wiki.rb
.include "../../lang/ruby/replace.mk"

post-install:
	${RM} ${PREFIX}/share/wesnoth/icons/Makefile*

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.5nb3
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=		SDL>=1.2.7
.include "../../devel/SDL/buildlink3.mk"
# configure script in 0.9.0 requests explicitly to
# use included SDL_ttf library
#.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
