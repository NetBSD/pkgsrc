# $NetBSD: Makefile,v 1.9 2025/02/02 13:05:04 pho Exp $

DISTNAME=	dependent-sum-0.7.2.0
PKGREVISION=	5
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
