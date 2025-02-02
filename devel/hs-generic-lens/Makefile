# $NetBSD: Makefile,v 1.10 2025/02/02 13:05:07 pho Exp $

DISTNAME=	generic-lens-2.2.2.0
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generically derive traversals, lenses and prisms
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-generic-lens-core/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
