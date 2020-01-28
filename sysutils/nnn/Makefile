# $NetBSD: Makefile,v 1.15 2020/01/28 14:31:19 sjmulder Exp $

DISTNAME=	nnn-2.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jarun/nnn/
COMMENT=	Optimized, feature-packed terminal file manager
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake pkg-config
USE_CURSES=	wide set_escdelay getmouse

.include "../../mk/bsd.prefs.mk"

# Crashes with NetBSD's libedit/libtermcap, see:
# https://github.com/jarun/nnn/issues/445
.if ${OPSYS} == "NetBSD"
READLINE_DEFAULT=	readline
.endif

# clock_gettime() on older glibc (eg RHEL 6), see:
# https://github.com/jarun/nnn/issues/453
MAKE_ENV.Linux+=	LDLIBS=-lrt

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	CFLAGS_OPTIMIZATION=
MAKE_ENV+=	CFLAGS_CURSES=${BUILDLINK_CFLAGS.curses:Q}
MAKE_ENV+=	LDLIBS_CURSES=${BUILDLINK_LDADD.curses:Q}

.include "options.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
