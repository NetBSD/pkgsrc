# $NetBSD: Makefile,v 1.10 2023/10/29 09:35:52 pho Exp $

DISTNAME=	errors-2.3.0
PKGREVISION=	6
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
