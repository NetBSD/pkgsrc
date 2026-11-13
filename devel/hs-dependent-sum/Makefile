# $NetBSD: Makefile,v 1.12 2026/11/13 14:38:55 pho Exp $

DISTNAME=	dependent-sum-0.7.2.0
PKGREVISION=	8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dependent sum type
LICENSE=	public-domain

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	some

.include "../../devel/hs-constraints-extras/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
