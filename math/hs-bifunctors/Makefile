# $NetBSD: Makefile,v 1.12 2023/10/29 09:48:51 pho Exp $

DISTNAME=	bifunctors-5.6.1
CATEGORIES=	math

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Bifunctors
LICENSE=	2-clause-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	th-abstraction

.include "../../devel/hs-assoc/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
