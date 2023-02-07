# $NetBSD: Makefile,v 1.4 2023/02/07 01:40:30 pho Exp $

DISTNAME=	constraints-extras-0.4.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility package for constraints
LICENSE=	modified-bsd

# Don't build or install an example program.
CONFIGURE_ARGS+=	-f-build-readme

.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
