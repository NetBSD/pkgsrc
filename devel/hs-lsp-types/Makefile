# $NetBSD: Makefile,v 1.11 2024/05/09 01:32:02 pho Exp $

DISTNAME=	lsp-types-2.2.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell library for the Microsoft Language Server Protocol, data types
LICENSE=	mit

# Do not build or install the example executable. We don't want it in
# pkgsrc.
HASKELL_DISABLE_EXECUTABLES+=	\
	generator

# lib:lsp-types
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../math/hs-mod/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../devel/hs-row-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"

# lib:metamodel
.include "../../devel/hs-file-embed/buildlink3.mk"

# lib:lsp-types-quickcheck
.include "../../devel/hs-generic-arbitrary/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-quickcheck-instances/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
