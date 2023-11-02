# $NetBSD: Makefile,v 1.8 2023/11/02 06:37:02 pho Exp $

DISTNAME=	unliftio-0.2.25.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The MonadUnliftIO typeclass along with a number of common instances
LICENSE=	mit

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
