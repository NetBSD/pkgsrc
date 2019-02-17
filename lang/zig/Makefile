# $NetBSD: Makefile,v 1.1 2019/02/17 12:33:40 maya Exp $

DISTNAME=	zig-0.3.0+8d2a9029
PKGNAME=	zig-0.3.0.20190217
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

post-patch:
	${CP} ${FILESDIR}/std_c_netbsd.zig ${WRKSRC}/std/c/netbsd.zig
	${MKDIR} ${WRKSRC}/std/os/netbsd
	${CP} ${FILESDIR}/std_os_netbsd_index.zig ${WRKSRC}/std/os/netbsd/index.zig
	${CP} ${FILESDIR}/std_os_netbsd_errno.zig ${WRKSRC}/std/os/netbsd/errno.zig

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../devel/lld/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
