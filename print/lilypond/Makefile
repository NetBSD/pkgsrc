# $NetBSD: Makefile,v 1.81 2012/09/15 10:06:11 obache Exp $
#

DISTNAME=	lilypond-2.14.2
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v2.14/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lilypond.org/
COMMENT=	GNU Music Typesetter
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont
BUILD_DEPENDS+=	tex-metapost-[0-9]*:../../graphics/tex-metapost
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison gmake gs:run makeinfo perl pkg-config msgfmt
USE_TOOLS+=		texi2html
MAKE_FILE=		GNUmakefile

.include "../../mk/bsd.prefs.mk"

TEXINFO_REQD=		4.11
GCC_REQD+=		3.0.5

GNU_CONFIGURE_INFODIR=	${PREFIX}/${PKGINFODIR}
INFO_DIR=		${GNU_CONFIGURE_INFODIR}
INFO_FILES=		YES

BUILD_DEPENDS+=		urw-fonts-[0-9]*:../../fonts/urw-fonts
BUILD_DEPENDS+=		fontforge>=20060125:../../fonts/fontforge
BUILD_DEPENDS+=		t1utils>=1.33:../../fonts/t1utils
CONFIGURE_ARGS+=	--with-ncsb-dir=${LOCALBASE}/share/fonts/urw
CONFIGURE_ARGS+=	--disable-optimising
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

REPLACE_PYTHON+= scripts/auxiliar/yyout2grammar.py
PLIST_SUBST+=	PKGVERSION=${PKGVERSION:S/nb${PKGREVISION}//}

# 1.7 coredumps when generating eps files
DEPENDS+=	potrace>=1.8:../../graphics/potrace

.if ${OPSYS} == "DragonFly"
CONFIGURE_ENV+= LEX="${PREFIX}/bin/flex"
.include "../../devel/flex/buildlink3.mk"
.else
USE_TOOLS+= flex
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
