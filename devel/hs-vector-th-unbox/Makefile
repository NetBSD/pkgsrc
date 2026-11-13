# $NetBSD: Makefile,v 1.17 2026/11/13 14:39:26 pho Exp $

DISTNAME=	vector-th-unbox-0.2.2
PKGREVISION=	11
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
