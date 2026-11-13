# $NetBSD: Makefile,v 1.3 2026/11/13 14:39:22 pho Exp $

DISTNAME=	tuples-0.1.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Small monomorphic tuples
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	primitive

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
