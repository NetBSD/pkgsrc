# $NetBSD: Makefile,v 1.9 2025/01/30 14:47:35 pho Exp $

DISTNAME=	constraints-0.14.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Constraint manipulation
LICENSE=	2-clause-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
