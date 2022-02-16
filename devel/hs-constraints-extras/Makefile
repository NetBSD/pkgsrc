# $NetBSD: Makefile,v 1.1 2022/02/16 05:00:36 pho Exp $

DISTNAME=	constraints-extras-0.3.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility package for constraints
LICENSE=	modified-bsd

# It's just an example but depends on converters/hs-aeson.
CONFIGURE_ARGS+=	-f-build-readme

.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
