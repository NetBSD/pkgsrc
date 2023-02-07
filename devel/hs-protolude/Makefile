# $NetBSD: Makefile,v 1.5 2023/02/07 01:40:47 pho Exp $

DISTNAME=	protolude-0.3.2
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sensible starting Prelude for building custom Preludes
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mtl-compat/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
