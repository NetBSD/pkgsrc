# $NetBSD: Makefile,v 1.130 2019/07/21 22:24:59 wiz Exp $

DISTNAME=	gnuplot-5.2.6
CATEGORIES+=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuplot.sourceforge.net/
COMMENT=	Portable interactive, function plotting utility
PKGREVISION=	2
#LICENSE=	gnuplot + BSD

API_VERSION=	${PKGVERSION_NOREV:C/([0-9])\.([0-9])\.([0-9])/\1.\2/}

CONFLICTS+=		gnuplot-nox11-[0-9]*

USE_LANGUAGES=		c
USE_TOOLS+=		makeinfo pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline=bsd
CONFIGURE_ARGS+=	--without-latex
CONFIGURE_ARGS+=	--without-tutorial
CONFIGURE_ARGS+=	ac_cv_prog_EMACS=
INFO_FILES=		yes
TEST_TARGET=		check

PLIST_SUBST+=		API_VERSION=${API_VERSION}
LDFLAGS.SunOS+=		-liconv

# Make this available to patch-src_variable.c so the font path can include pkgsrc fonts.
SUBST_CLASSES+=		fontpath
SUBST_STAGE.fontpath=	pre-configure
SUBST_MESSAGE.fontpath=	Fixing font path.
SUBST_FILES.fontpath=	src/variable.c
SUBST_SED.fontpath=	-e 's,@PKGSRC_PREFIX@,"${PREFIX}",'

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
