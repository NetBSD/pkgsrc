# $NetBSD: Makefile,v 1.9 2025/03/05 03:39:12 pho Exp $

DISTNAME=	generic-lens-core-2.2.1.0
PKGREVISION=	7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generically derive traversals, lenses and prisms
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../math/hs-indexed-profunctors/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
