# $NetBSD: Makefile,v 1.24 2023/03/07 06:09:02 charlotte Exp $

DISTNAME=	janet-1.27.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=janet-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://janet-lang.org/
COMMENT=	Functional and imperative programming language
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c99

BUILD_TARGET=	all build/janet.pc
TEST_TARGET=	test

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	JANET_MANPATH=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	JANET_PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
MAKE_FLAGS+=	JANET_BUILD='"\"pkgsrc\""'

LDFLAGS.SunOS+=	-lsocket -lnsl

REPLACE_INTERPRETER+=	janet
REPLACE.janet.old=	.*
REPLACE.janet.new=	${PREFIX}/bin/janet
REPLACE_FILES.janet=	jpm

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		build/janet.pc

.include "../../mk/bsd.pkg.mk"
