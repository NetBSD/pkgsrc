# $NetBSD: Makefile,v 1.1 2020/03/30 16:52:48 riastradh Exp $

.include "../../finance/hledger/common.mk"

HASKELL_PKG_NAME=	hledger
CATEGORIES=		finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simonmichael/hledger/
COMMENT=	Plain-text accounting tool
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

.include "../../devel/hs-utility-ht/buildlink3.mk"
.include "../../devel/hs-wizards/buildlink3.mk"
.include "../../finance/hledger-lib/buildlink3.mk"
.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../textproc/hs-lucid/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
