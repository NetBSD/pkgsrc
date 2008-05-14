# $NetBSD: Makefile,v 1.52 2008/05/14 20:25:16 sborrill Exp $
#

DISTNAME=	lilypond-2.10.33
CATEGORIES=	print
MASTER_SITES=	http://lilypond.org/download/sources/v2.10/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lilypond.org/web/
COMMENT=	GNU Music Typesetter

DEPENDS+=	ec-fonts-mftraced-[0-9]*:../../fonts/ec-fonts-mftraced

BUILDLINK_API_DEPENDS.mftrace+=	mftrace>=1.1.0

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake gs:run makeinfo perl msgfmt
MAKE_FILE=		GNUmakefile

.include "../../mk/bsd.prefs.mk"

TEXINFO_REQD=		4.8
GCC_REQD+=		3.0.5

GNU_CONFIGURE_INFODIR=	${PREFIX}/${PKGINFODIR}
INFO_DIR=		${GNU_CONFIGURE_INFODIR}
INFO_FILES=		YES

CONFIGURE_ARGS+=	--disable-optimising
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYTHON_VERSIONS_ACCEPTED= 23 21
# 22 has some regular expression problem

PLIST_SUBST+=	PKGVERSION=${PKGVERSION:S/nb${PKGREVISION}//}

# 1.7 coredumps when generating eps files
DEPENDS+=	potrace>=1.8:../../graphics/potrace

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/mftrace/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
