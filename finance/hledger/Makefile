# $NetBSD: Makefile,v 1.6 2022/01/18 02:48:16 pho Exp $

DISTNAME=	hledger-1.21
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Plain-text accounting tool
LICENSE=	gnu-gpl-v3

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../finance/hs-Decimal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../finance/hledger-lib/buildlink3.mk"
.include "../../textproc/hs-lucid/buildlink3.mk"
.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-tabular/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-timeit/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.include "../../devel/hs-wizards/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Kludge: We need to run this in a UTF-8 locale; otherwise GHC is
# unhappy.  But we also need to make this override the C locale that
# pkgsrc tries hard to ensure everything gets built in for the sake of
# reproducibility, so it has to come _after_ bsd.pkg.mk.  This would be
# C.UTF-8, but C.UTF-8 was only recently introduced into NetBSD, so
# let's pick a locale that is pretty universally supported even if not
# exactly appropriate for this.
MAKE_ENV+=	LC_ALL=en_US.UTF-8
# The root cause of the problem is in hledger-lib/Hledger/Utils.hs
# (embedFileRelative). It uses embedStringFile from file-embed
# (devel/hs-file-embed) but without changing the locale encoding to
# UTF-8, and the file to be embedded
# (hledger/embeddedfiles/hledger.info) does contain non-ASCII
# characters. Using with-utf8
# (http://hackage.haskell.org/package/with-utf8) is probably the best
# solution.
