# $NetBSD: Makefile,v 1.2 2022/02/26 03:57:51 pho Exp $

DISTNAME=	constraints-extras-0.3.2.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility package for constraints
LICENSE=	modified-bsd

# It's just an example but depends on converters/hs-aeson.
CONFIGURE_ARGS+=	-f-build-readme

.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
