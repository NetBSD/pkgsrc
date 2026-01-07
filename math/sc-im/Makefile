# $NetBSD: Makefile,v 1.57 2026/01/07 08:47:53 wiz Exp $

DISTNAME=	sc-im-0.8.4
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=andmarti1424/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/andmarti1424/sc-im/
COMMENT=	Curses-based spreadsheet program based on sc
LICENSE=	original-bsd

BUILD_DIRS=	src
INSTALL_DIRS=	src

.include "../../mk/bsd.prefs.mk"

# pkg-config to avoid broken Makefile self-configuration
USE_TOOLS+=	gmake pkg-config yacc sed bash:run

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

REPLACE_BASH+=	src/scopen

# gnuplot is invoked through the shell, no need to check at compile time
CFLAGS+=	-DGNUPLOT
# needed for PATH_MAX due to std=c99 set above (at least on Illumos)
CFLAGS+=	-D_XOPEN_SOURCE
# formats/ods.c forgets to include some header(s), fixed in 0.8.4
CFLAGS+=	-Wno-error=implicit-function-declaration

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	src/Makefile
SUBST_VARS.pkgsrc=	CC PREFIX PKGMANDIR SED YACC
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

MAKE_ENV+=	CFLAGS_CURSES=${BUILDLINK_CFLAGS.ncurses:Q}
MAKE_ENV+=	LDLIBS_CURSES=${BUILDLINK_LDADD.ncurses:Q}
MAKE_ENV+=	CFLAGS_DL=${BUILDLINK_CFLAGS.dl:Q}
MAKE_ENV+=	LDLIBS_DL=${BUILDLINK_LDADD.dl:Q}
MAKE_ENV+=	LDLIBS=${LDLIBS:Q}

.include "options.mk"

# tries to access internal cchar_t struct, incompatible with
# NetBSD curses
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
