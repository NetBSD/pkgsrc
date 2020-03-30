# $NetBSD: Makefile,v 1.1 2020/03/30 16:52:48 riastradh Exp $

.include "../../finance/hledger/common.mk"

HASKELL_PKG_NAME=	hledger-lib
CATEGORIES=		finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simonmichael/hledger/
COMMENT=	Plain-text accounting tool
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../devel/hs-call-stack/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-fgl/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-hashtables/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-pretty-show/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-tabular/buildlink3.mk"
.include "../../devel/hs-tasty-hunit/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-timeit/buildlink3.mk"
.include "../../devel/hs-uglymemo/buildlink3.mk"
.include "../../finance/hs-Decimal/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../textproc/hs-cassava-megaparsec/buildlink3.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
