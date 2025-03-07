# $NetBSD: Makefile,v 1.1 2025/03/07 16:25:36 pho Exp $

DISTNAME=	tuples-0.1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Small monomorphic tuples
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	primitive

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
