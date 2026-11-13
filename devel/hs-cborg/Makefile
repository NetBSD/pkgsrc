# $NetBSD: Makefile,v 1.16 2026/11/13 14:38:51 pho Exp $

DISTNAME=	cborg-0.2.10.0
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Concise Binary Object Representation (CBOR)
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim

.include "../../devel/hs-half/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
