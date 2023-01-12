# $NetBSD: Makefile,v 1.79 2023/01/12 19:32:53 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}

USE_TOOLS+=	perl:run

PLIST_VARS+=	RISCV
.if ${PKG_BUILD_OPTIONS.llvm:Mllvm-target-riscv}
PLIST.RISCV=	yes
.endif

PLIST_VARS+=	ARM
.if	${PKG_BUILD_OPTIONS.llvm:Mllvm-target-arm} ||	\
	${PKG_BUILD_OPTIONS.llvm:Mllvm-target-aarch64}
PLIST.ARM=	yes
.endif

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
