# $NetBSD: Makefile,v 1.18 2022/08/20 21:01:27 wiz Exp $

DISTNAME=	zig-0.9.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

# https://github.com/ziglang/zig/issues/12534
BROKEN=		"No support for llvm 14 yet."

USE_CMAKE=	yes
USE_TOOLS+=	bash:run
USE_LANGUAGES=	c c++14

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DDESTDIR=${DESTDIR}

REPLACE_BASH+=	lib/libcxxabi/src/demangle/cp-to-llvm.sh

CHECK_PORTABILITY_SKIP+=	ci/azure/macos_script
BUILDLINK_TRANSFORM+=		rm:-Werror

.include "../../devel/lld/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
