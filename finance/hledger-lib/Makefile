# $NetBSD: Makefile,v 1.18 2024/05/09 01:32:21 pho Exp $

DISTNAME=	hledger-lib-1.33.1
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Plain-text accounting tool
LICENSE=	gnu-gpl-v3

# The compiler consumes about 3.5 GiB of memory when -O2 is in effect. It
# keeps getting swapped in and out and never finishes the compilation.
HASKELL_OPTIMIZATION_LEVEL=	1

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-call-stack/buildlink3.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../textproc/hs-cassava-megaparsec/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../finance/hs-Decimal/buildlink3.mk"
.include "../../textproc/hs-doclayout/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../devel/hs-hashtables/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-microlens/buildlink3.mk"
.include "../../devel/hs-microlens-th/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-pretty-simple/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-tabular/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-tasty-hunit/buildlink3.mk"
.include "../../devel/hs-terminal-size/buildlink3.mk"
.include "../../textproc/hs-text-ansi/buildlink3.mk"
.include "../../devel/hs-timeit/buildlink3.mk"
.include "../../devel/hs-uglymemo/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../misc/hs-pager/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
