# $NetBSD: Makefile,v 1.16 2023/02/07 01:40:54 pho Exp $

DISTNAME=	vector-0.13.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Efficient Arrays for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector-stream/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
