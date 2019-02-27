# $NetBSD: Makefile,v 1.2 2019/02/27 10:46:16 maya Exp $

DISTNAME=	zig-0.3.0+c59ce046
PKGNAME=	zig-0.3.0.20190227
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/builds/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ziglang.org/
COMMENT=	Programming language designed for robustness and clarity
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CHECK_PORTABILITY_SKIP+=	ci/azure/macos_script
BUILDLINK_TRANSFORM+=		rm:-Werror

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
# Using builtin lld
#.include "../../devel/lld/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
