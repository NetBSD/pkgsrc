# $NetBSD: Makefile,v 1.9 2023/10/09 04:54:32 pho Exp $

DISTNAME=	these-1.1.1.1
PKGREVISION=	6
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Either-or-both data type
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	hashable

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-assoc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
