# $NetBSD: Makefile,v 1.8 2019/06/12 21:11:44 sjmulder Exp $

DISTNAME=	nnn-2.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jarun/nnn/
COMMENT=	Optimized, feature-packed terminal file manager
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake pkg-config
# build without readline unless option set (see options.mk)
BUILD_TARGET=	norl

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	CFLAGS_OPTIMIZATION=
MAKE_ENV+=	CFLAGS_CURSES=${BUILDLINK_CFLAGS.ncursesw:Q}
MAKE_ENV+=	LDLIBS_CURSES=${BUILDLINK_LDADD.ncursesw:Q}

# Requires mousemask(), getmouse() functions not in NetBSD curses
.include "../../devel/ncursesw/buildlink3.mk"

# After ncursesw so readline doesn't add the non-wide ncurses which
# would sabotage the ncursesw buildlink with '__nonexistent__'
.include "options.mk"

.include "../../mk/bsd.pkg.mk"
