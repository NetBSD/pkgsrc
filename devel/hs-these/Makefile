# $NetBSD: Makefile,v 1.18 2026/11/13 14:39:21 pho Exp $

DISTNAME=	these-1.2.1
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Either-or-both data type
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable

.include "../../devel/hs-assoc/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
