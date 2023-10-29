# $NetBSD: Makefile,v 1.4 2023/10/29 09:37:26 pho Exp $

DISTNAME=	dec-0.0.5
PKGREVISION=	2
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
