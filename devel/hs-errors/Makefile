# $NetBSD: Makefile,v 1.7 2023/01/26 09:33:08 pho Exp $

DISTNAME=	errors-2.3.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Simplified error-handling
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text	\
	transformers-compat

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
