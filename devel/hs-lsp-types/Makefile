# $NetBSD: Makefile,v 1.7 2023/10/31 04:01:39 pho Exp $

DISTNAME=	lsp-types-2.0.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell library for the Microsoft Language Server Protocol, data types
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

# Don't build or install the executable "generator".
SUBST_CLASSES+=		exe
SUBST_STAGE.exe=	post-extract
SUBST_FILES.exe=	lsp-types.cabal
SUBST_SED.exe=		-e '/^executable generator/a\${.newline}  buildable: False'

# lib:lsp-types
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../converters/hs-lens-aeson/buildlink3.mk"
.include "../../math/hs-mod/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../devel/hs-row-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:metamodel
.include "../../devel/hs-file-embed/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
