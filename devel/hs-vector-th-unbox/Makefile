# $NetBSD: Makefile,v 1.9 2023/01/25 18:50:48 pho Exp $

DISTNAME=	vector-th-unbox-0.2.2
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Deriver for Data.Vector.Unboxed using Template Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	template-haskell	\
	vector

.include "../../mk/haskell.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
