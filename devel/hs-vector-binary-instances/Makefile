# $NetBSD: Makefile,v 1.16 2026/11/13 14:39:25 pho Exp $

DISTNAME=	vector-binary-instances-0.2.5.2
PKGREVISION=	13
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Instances of Data.Binary for vector
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	vector

.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
