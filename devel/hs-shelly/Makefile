# $NetBSD: Makefile,v 1.3 2023/02/07 01:40:49 pho Exp $

DISTNAME=	shelly-1.10.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Shell-like (systems) programming in Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	unix-compat

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-enclosed-exceptions/buildlink3.mk"
.include "../../devel/hs-lifted-async/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
