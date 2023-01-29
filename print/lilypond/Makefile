# $NetBSD: Makefile,v 1.144 2023/01/29 21:17:36 ryoon Exp $

DISTNAME=		lilypond-2.24.0
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		https://lilypond.org/download/sources/v2.24/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://lilypond.org/
COMMENT=		GNU Music Typesetter
LICENSE=		gnu-gpl-v3 AND gnu-fdl-v1.3 AND ofl-v1.1

BUILD_DEPENDS+=		tex-fontinst-[0-9]*:../../fonts/tex-fontinst
BUILD_DEPENDS+=		tex-metafont-[0-9]*:../../fonts/tex-metafont
BUILD_DEPENDS+=		tex-metapost-[0-9]*:../../graphics/tex-metapost
BUILD_DEPENDS+=		urw-fonts-[0-9]*:../../fonts/urw-fonts
BUILD_DEPENDS+=		intlfonts-[0-9]*:../../fonts/intlfonts
BUILD_DEPENDS+=		font-cronyx-cyrillic-[0-9]*:../../fonts/font-cronyx-cyrillic
BUILD_DEPENDS+=		kochi-ttf-[0-9]*:../../fonts/kochi-ttf
BUILD_DEPENDS+=		fontforge>=20120731:../../fonts/fontforge
BUILD_DEPENDS+=		t1utils>=1.33:../../fonts/t1utils
BUILD_DEPENDS+=		dblatex-[0-9]*:../../textproc/dblatex
BUILD_DEPENDS+=		rsync-[0-9]*:../../net/rsync
BUILD_DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm
BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

DEPENDS+=		tex-cyrillic-[0-9]*:../../print/tex-cyrillic
DEPENDS+=		tex-lh-[0-9]*:../../fonts/tex-lh
DEPENDS+=		tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=		tex-epsf-[0-9]*:../../print/tex-epsf
DEPENDS+=		tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=		tex-tex-gyre-[0-9]*:../../fonts/tex-tex-gyre
DEPENDS+=		potrace>=1.8:../../graphics/potrace

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++11
USE_TOOLS+=		bison gmake gs:run makeinfo perl pkg-config msgfmt
USE_TOOLS+=		texi2html zip
MAKE_FILE=		GNUmakefile

.include "../../mk/bsd.prefs.mk"

TEXINFO_REQD=		6.1

GNU_CONFIGURE_INFODIR=	${PREFIX}/${PKGINFODIR}
INFO_DIR=		${GNU_CONFIGURE_INFODIR}
INFO_FILES=		YES

CONFIGURE_ARGS+=	--disable-optimising
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

BUILD_TARGET=		all bytecode
INSTALL_TARGET=		install install-bytecode

REPLACE_PYTHON+=		scripts/build/www_post.py
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	find ${DESTDIR}${PREFIX} -type d -name __pycache__ | xargs rm -rf

.include "../../devel/boehm-gc/buildlink3.mk"
# needs FlexLexer.h
# make sure we use the same version for that file and the flex binary
FLEX_REQD=		2.6.0
BUILDLINK_API_DEPENDS.flex+=	flex>=2.6.0
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
