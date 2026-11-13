# $NetBSD: Makefile,v 1.16 2026/11/13 14:39:12 pho Exp $

DISTNAME=	protolude-0.3.4
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sensible starting Prelude for building custom Preludes
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim	\
	hashable

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mtl-compat/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
