# $NetBSD: Makefile,v 1.14 2025/02/02 13:05:30 pho Exp $

DISTNAME=	vector-th-unbox-0.2.2
PKGREVISION=	8
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
