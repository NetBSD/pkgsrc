# $NetBSD: Makefile,v 1.6 2023/10/09 04:54:33 pho Exp $

DISTNAME=	unliftio-0.2.23.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The MonadUnliftIO typeclass along with a number of common instances
LICENSE=	mit

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
