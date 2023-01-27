# $NetBSD: Makefile,v 1.3 2023/01/27 14:01:26 pho Exp $

DISTNAME=	generic-lens-2.2.1.0
PKGREVISION=	1
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
