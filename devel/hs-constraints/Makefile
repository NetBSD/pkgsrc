# $NetBSD: Makefile,v 1.11 2025/03/05 03:39:07 pho Exp $

DISTNAME=	constraints-0.14.2
PKGREVISION=	2
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
