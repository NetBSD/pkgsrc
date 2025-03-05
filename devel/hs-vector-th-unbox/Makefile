# $NetBSD: Makefile,v 1.15 2025/03/05 03:39:36 pho Exp $

DISTNAME=	vector-th-unbox-0.2.2
PKGREVISION=	9
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
