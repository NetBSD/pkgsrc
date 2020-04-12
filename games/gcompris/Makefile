# $NetBSD: Makefile,v 1.98 2020/04/12 08:28:39 adam Exp $

DISTNAME=	gcompris-17.05
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://gcompris.net/download/gtk/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://gcompris.net/
COMMENT=	Educational games for children
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config perl bash:run
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
USE_TOOLS+=	texi2html
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--enable-sdlmixer

REPLACE_PYTHON+=	boards/voices/check_voices.py

REPLACE_BASH+=		boards/voices/generate_voices_rcc.sh
REPLACE_BASH+=		boards/voices/updateVoices.sh

# Junk to clean up in post-install.
TO_REMOVE+=		share/gcompris/boards/anim/Makefile
TO_REMOVE+=		share/gcompris/boards/anim/Makefile.am
TO_REMOVE+=		share/gcompris/boards/anim/Makefile.in
TO_REMOVE+=		share/gcompris/boards/explore_world_animals/Makefile.am
TO_REMOVE+=		share/gcompris/boards/geo_country/usa/Makefile.am
TO_REMOVE+=		share/gcompris/boards/gnumch/Makefile.am

# Basically not going to get ported to Python 3 ever
# Current development is focused on the Qt version
PYTHON_VERSIONS_ACCEPTED=	27

post-install:
.for file in ${TO_REMOVE}
	${RM} -f ${DESTDIR}${PREFIX}/${file}
.endfor

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
