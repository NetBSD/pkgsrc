# $NetBSD: Makefile,v 1.29 2021/08/06 01:38:57 sjmulder Exp $

DISTNAME=	sc-im-0.8.2
PKGREVISION=	1
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
USE_TOOLS+=	gmake pkg-config yacc bash:run

REPLACE_BASH+=	src/scopen

# gnuplot is invoked through the shell, no need to check at compile time
CFLAGS+=	-DGNUPLOT

MAKE_ENV+=	CFLAGS_CURSES=${BUILDLINK_CFLAGS.ncursesw:Q}
MAKE_ENV+=	LDLIBS_CURSES=${BUILDLINK_LDADD.ncursesw:Q}
MAKE_ENV+=	CFLAGS_DL=${BUILDLINK_CFLAGS.dl:Q}
MAKE_ENV+=	LDLIBS_DL=${BUILDLINK_LDADD.dl:Q}
MAKE_ENV+=	LDLIBS=${LDLIBS:Q}

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

# Include after ncursesw bl3, otherwise ncurses bl3 (non-wide), included
# as a transitive dependency of lua, sabotages the -lncurses transform.
.include "options.mk"

.include "../../mk/bsd.pkg.mk"
