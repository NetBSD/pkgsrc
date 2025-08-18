# $NetBSD: Makefile,v 1.6 2025/08/18 05:29:33 wiz Exp $

DISTNAME=	hashcat-7.0.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://hashcat.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hashcat.net/
COMMENT=	World's fastest and most advanced password recovery utility
LICENSE=	mit

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake gsed perl:run

BUILD_TARGET=	hashcat
MAKE_ENV+=	SHARED=1
MAKE_ENV+=	USE_SYSTEM_XXHASH=1
MAKE_ENV+=	USE_SYSTEM_ZLIB=1
.if ${MACHINE_ARCH} == "aarch64"
MAKE_ENV+=	IS_ARM=1
CFLAGS+=	-march=armv8-a+fp+simd
.else
MAKE_ENV+=	IS_ARM=0
.endif

.include "../../mk/bsd.fast.prefs.mk"
# see include/common.h
BROKEN_ON_PLATFORM+=	${BIGENDIANPLATFORMS}

REPLACE_PERL=	tools/*.pl
REPLACE_PYTHON=	tools/*.py

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/hashcat/sort_r.h.orig
	${RM} ${DESTDIR}${PREFIX}/include/hashcat/terminal.h.orig

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
