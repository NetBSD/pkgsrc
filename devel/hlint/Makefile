# $NetBSD: Makefile,v 1.5 2022/02/26 03:57:46 pho Exp $

DISTNAME=	hlint-3.3.6
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell source code suggestions
LICENSE=	modified-bsd

BROKEN=		"${PKGBASE} is currently incompatible with GHC 9.2.x"
BROKEN+=	"Work is underway: https://github.com/ndmitchell/hlint/issues/1314"

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../sysutils/hs-filepattern/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser-ex/buildlink3.mk"
.include "../../devel/hs-refact/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-hscolour/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
