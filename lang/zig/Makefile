# $NetBSD: Makefile,v 1.24 2023/01/30 21:01:42 nikita Exp $

DISTNAME=	zig-0.10.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	bash:run
USE_LANGUAGES=	c c++14

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DDESTDIR=${DESTDIR}
# avoid full-cu-features available to build host,
# in other words ensure that we run everywhere
CMAKE_ARGS+=	-DZIG_TARGET_MCPU=baseline

CHECK_PORTABILITY_SKIP+=	ci/azure/macos_script
BUILDLINK_TRANSFORM+=		rm:-Werror

UNLIMIT_RESOURCES=	stacksize

# \todo: There is currently an issue building this as a PIE
MKPIE_SUPPORTED=	no
# RELRO checks fail for this package at the moment
RELRO_SUPPORTED=	no

.include "../../devel/lld/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
