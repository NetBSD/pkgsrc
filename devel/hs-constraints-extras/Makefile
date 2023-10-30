# $NetBSD: Makefile,v 1.6 2023/10/30 08:02:31 pho Exp $

DISTNAME=	constraints-extras-0.4.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility package for constraints
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	constraints	\
	template-haskell

# Don't build or install an example program.
CONFIGURE_ARGS+=	-f-build-readme

.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
