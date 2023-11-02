# $NetBSD: Makefile,v 1.5 2023/11/02 06:36:26 pho Exp $

DISTNAME=	dec-0.0.5
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Decidable propositions
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-void/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
