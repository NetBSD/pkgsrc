# $NetBSD: Makefile,v 1.4 2020/04/05 13:36:27 nia Exp $

DISTNAME=	janet-1.8.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=janet-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://janet-lang.org/
COMMENT=	Functional and imperative programming language
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c99

BUILD_TARGET=	all build/janet.pc
TEST_TARGET=	test

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
MAKE_FLAGS+=	JANET_BUILD='"\"pkgsrc\""'

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

REPLACE_INTERPRETER+=	janet
REPLACE.janet.old=	.*
REPLACE.janet.new=	${PREFIX}/bin/janet
REPLACE_FILES.janet=	auxbin/jpm

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		build/janet.pc

.include "../../mk/bsd.pkg.mk"
