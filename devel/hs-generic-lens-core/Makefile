# $NetBSD: Makefile,v 1.10 2025/08/13 11:06:40 pho Exp $

DISTNAME=	generic-lens-core-2.2.1.0
PKGREVISION=	8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generically derive traversals, lenses and prisms
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../math/hs-indexed-profunctors/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
