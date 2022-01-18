# $NetBSD: Makefile,v 1.2 2022/01/18 02:48:21 pho Exp $

DISTNAME=	tls-session-manager-0.0.4
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	In-memory TLS session manager
LICENSE=	modified-bsd

.include "../../devel/hs-auto-update/buildlink3.mk"
.include "../../devel/hs-basement/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-psqueues/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
