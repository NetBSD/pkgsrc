# $NetBSD: Makefile,v 1.15 2025/08/13 11:06:38 pho Exp $

DISTNAME=	errors-2.3.0
PKGREVISION=	11
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Simplified error-handling
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text	\
	transformers	\
	transformers-compat

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
