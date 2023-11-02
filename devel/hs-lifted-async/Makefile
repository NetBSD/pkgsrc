# $NetBSD: Makefile,v 1.7 2023/11/02 06:36:43 pho Exp $

DISTNAME=	lifted-async-0.10.2.4
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run lifted IO operations asynchronously and wait for their results
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	constraints

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
