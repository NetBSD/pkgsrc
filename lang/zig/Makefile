# $NetBSD: Makefile,v 1.4 2020/03/20 11:42:38 tnn Exp $

DISTNAME=	zig-0.4.0
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
BROKEN=		"expected LLVM 8.x but found 9.0.1"

CHECK_PORTABILITY_SKIP+=	ci/azure/macos_script
BUILDLINK_TRANSFORM+=		rm:-Werror

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
# Using builtin lld
#.include "../../devel/lld/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
