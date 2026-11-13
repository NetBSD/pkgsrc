# $NetBSD: Makefile,v 1.13 2026/11/13 14:39:17 pho Exp $

DISTNAME=	some-1.0.6
PKGREVISION=	6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Existential type: Some
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
