# $NetBSD: Makefile,v 1.2 2020/03/30 17:52:39 riastradh Exp $

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

# XXX Kludge: We need to run this in a UTF-8 locale; otherwise GHC is
# unhappy.  But we also need to make this override the C locale that
# pkgsrc tries hard to ensure everything gets built in for the sake of
# reproducibility, so it has to come _after_ bsd.pkg.mk.  This would be
# C.UTF-8, but C.UTF-8 was only recently introduced into NetBSD, so
# let's pick a locale that is pretty universally supported even if not
# exactly appropriate for this.
MAKE_ENV+=	LC_ALL=en_US.UTF-8
