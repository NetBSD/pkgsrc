# $NetBSD: Makefile,v 1.13 2025/02/02 13:05:30 pho Exp $

DISTNAME=	vector-binary-instances-0.2.5.2
PKGREVISION=	10
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
