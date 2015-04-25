# $NetBSD: Makefile,v 1.97 2015/04/25 14:23:12 tnn Exp $

DISTNAME=	gnuplot-5.0.0
API_VERSION=	${PKGVERSION:C/([0-9])\.([0-9])\.([0-9])/\1.\2/}
CATEGORIES+=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuplot.sourceforge.net/
COMMENT=	Portable interactive, function plotting utility
PKGREVISION=	1
#LICENSE=	gnuplot + BSD

CONFLICTS+=		gnuplot-nox11-[0-9]*

PATCHDIR=		${.CURDIR}/../../graphics/gnuplot/patches
DISTINFO_FILE=		${.CURDIR}/../../graphics/gnuplot/distinfo

USE_LANGUAGES=		c
USE_TOOLS+=		makeinfo pkg-config gmake
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--enable-history-file
CONFIGURE_ARGS+=	--with-plot=${PREFIX}
CONFIGURE_ARGS+=	--without-latex
CONFIGURE_ARGS+=	--without-lisp-files
CONFIGURE_ARGS+=	--without-tutorial
CONFIGURE_ARGS+=	ac_cv_prog_EMACS=
INFO_FILES=		yes

# to build doc/gnuplot.pdf
BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=		tex-ucs-[0-9]*:../../print/tex-ucs

CONFIGURE_ARGS+=	--with-readline=bsd
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

PLIST_SUBST+=		API_VERSION=${API_VERSION}
LDFLAGS.SunOS+=		-liconv

# Make this available to patch-ah so the font path can include pkgsrc fonts.
SUBST_CLASSES+=		fontpath
SUBST_STAGE.fontpath=	pre-configure
SUBST_MESSAGE.fontpath=	Fixing font path.
SUBST_FILES.fontpath=	src/variable.c
SUBST_SED.fontpath=	-e 's,@PKGSRC_PREFIX@,"${PREFIX}",'

post-build:
	(cd ${WRKSRC}/docs; ${GMAKE} gnuplot.pdf)

post-install:
	(cd ${WRKSRC}/docs; \
	${INSTALL_DATA} gnuplot.pdf ${DESTDIR}${PREFIX}/share/gnuplot/${API_VERSION})

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
