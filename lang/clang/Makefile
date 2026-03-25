# $NetBSD: Makefile,v 1.95 2026/03/25 22:56:25 wiz Exp $

.include "Makefile.common"

PKGNAME=	clang-${LLVM_VERSION}

COMMENT=	C language family frontend for LLVM

USE_TOOLS+=	perl:run

# Certain header files are generated, and can only be generated
# if llvm has support for the target.
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
