# $NetBSD: Makefile,v 1.12 2021/11/23 20:55:44 wiz Exp $

DISTNAME=	zig-0.8.0
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

BROKEN=		"Needs a new upstream release that works with llvm-13"
# https://github.com/ziglang/zig/issues/10187

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
