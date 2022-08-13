# $NetBSD: Makefile,v 1.73 2022/08/13 09:58:03 tnn Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}

USE_TOOLS+=	perl:run

PLIST_VARS+=	RISCV
.if ${PKG_BUILD_OPTIONS.llvm:Mllvm-target-riscv}
PLIST.RISCV=	yes
.endif

.include "../../mk/bsd.pkg.mk"
