# $NetBSD: Makefile,v 1.47 2024/05/07 17:17:01 nia Exp $

DISTNAME=	sc-im-0.8.3
PKGREVISION=	3
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
USE_TOOLS+=	gmake pkg-config bison bash:run

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

REPLACE_BASH+=	src/scopen

# gnuplot is invoked through the shell, no need to check at compile time
CFLAGS+=	-DGNUPLOT
# needed for PATH_MAX due to std=c99 set above (at least on Illumos)
CFLAGS+=	-D_XOPEN_SOURCE

MAKE_ENV+=	CFLAGS_CURSES=${BUILDLINK_CFLAGS.ncurses:Q}
MAKE_ENV+=	LDLIBS_CURSES=${BUILDLINK_LDADD.ncurses:Q}
MAKE_ENV+=	CFLAGS_DL=${BUILDLINK_CFLAGS.dl:Q}
MAKE_ENV+=	LDLIBS_DL=${BUILDLINK_LDADD.dl:Q}
MAKE_ENV+=	LDLIBS=${LDLIBS:Q}

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "options.mk"

# tries to access internal cchar_t struct, incompatible with
# NetBSD curses
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
