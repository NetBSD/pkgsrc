# $NetBSD: Makefile,v 1.16 2026/11/13 14:38:56 pho Exp $

DISTNAME=	errors-2.3.0
PKGREVISION=	12
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
