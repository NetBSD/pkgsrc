# $NetBSD: Makefile,v 1.4 2022/08/29 12:06:42 wiz Exp $

DISTNAME=	purescript-cst-0.5.0.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PureScript Programming Language Concrete Syntax Tree
LICENSE=	modified-bsd

USE_TOOLS+=	happy

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-microlens/buildlink3.mk"
.include "../../devel/hs-protolude/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-serialise/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
