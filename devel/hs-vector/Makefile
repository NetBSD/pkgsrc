# $NetBSD: Makefile,v 1.25 2026/11/13 14:39:25 pho Exp $

DISTNAME=	vector-0.13.2.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Efficient Arrays for Haskell
LICENSE=	modified-bsd

# lib:vector
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector-stream/buildlink3.mk"

# lib:benchmarks-O2
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
