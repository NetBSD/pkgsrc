# $NetBSD: Makefile,v 1.71 2011/07/31 09:12:46 ryoon Exp $
#

DISTNAME=	lilypond-2.14.2
CATEGORIES=	print
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v2.14/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lilypond.org/
COMMENT=	GNU Music Typesetter
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake gs:run makeinfo perl pkg-config msgfmt
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

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
