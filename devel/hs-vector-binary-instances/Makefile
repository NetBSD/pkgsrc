# $NetBSD: Makefile,v 1.10 2023/10/09 04:54:34 pho Exp $

DISTNAME=	vector-binary-instances-0.2.5.2
PKGREVISION=	7
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
