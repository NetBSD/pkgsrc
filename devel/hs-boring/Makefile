# $NetBSD: Makefile,v 1.3 2023/10/09 04:54:09 pho Exp $

DISTNAME=	boring-0.2
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Boring and Absurd types
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
