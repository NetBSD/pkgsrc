# $NetBSD: Makefile,v 1.4 2023/02/07 01:40:42 pho Exp $

DISTNAME=	lifted-async-0.10.2.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run lifted IO operations asynchronously and wait for their results
LICENSE=	modified-bsd

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
