# $NetBSD: Makefile,v 1.9 2023/02/07 01:40:54 pho Exp $

DISTNAME=	vector-binary-instances-0.2.5.2
PKGREVISION=	6
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
