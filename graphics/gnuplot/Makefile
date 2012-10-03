# $NetBSD: Makefile,v 1.63.2.1 2012/10/03 12:08:02 spz Exp $

DISTNAME=	gnuplot-4.6.0
PKGREVISION=	2
CATEGORIES+=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuplot.sourceforge.net/
COMMENT=	Portable interactive, function plotting utility

CONFLICTS+=		gnuplot-nox11-[0-9]*

PATCHDIR=		${.CURDIR}/../../graphics/gnuplot/patches
DISTINFO_FILE=		${.CURDIR}/../../graphics/gnuplot/distinfo

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo pkg-config gmake
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--enable-history-file
CONFIGURE_ARGS+=	--with-plot=${PREFIX}
CONFIGURE_ARGS+=	--without-latex
CONFIGURE_ARGS+=	--without-lisp-files
CONFIGURE_ARGS+=	--without-tutorial
INFO_FILES=		yes
USE_LANGUAGES=		c

# Use BSD editline wherever possible:
.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-readline=bsd
.include "../../mk/curses.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
.include "../../devel/readline/buildlink3.mk"
.endif

# Make this available to patch-ah so the font path can include pkgsrc fonts.
SUBST_CLASSES+=		fontpath
SUBST_STAGE.fontpath=	pre-configure
SUBST_MESSAGE.fontpath=	Fixing font path.
SUBST_FILES.fontpath=	src/variable.c
SUBST_SED.fontpath=	-e 's,@PKGSRC_PREFIX@,"${PREFIX}",'

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
