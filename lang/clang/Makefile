# $NetBSD: Makefile,v 1.72 2022/08/12 19:03:39 tnn Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}

USE_TOOLS+=	perl:run

PLIST_VARS+=	RISCV
.if !empty(PKG_BUILD_OPTIONS.llvm:Mllvm-target-riscv)
PLIST.RISCV=	yes
.endif

.include "../../mk/bsd.pkg.mk"
