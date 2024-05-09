# $NetBSD: Makefile,v 1.10 2024/05/09 01:32:34 pho Exp $

DISTNAME=	tls-session-manager-0.0.5
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	In-memory TLS session manager
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	auto-update	\
	bytestring

.include "../../devel/hs-auto-update/buildlink3.mk"
.include "../../devel/hs-basement/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../security/hs-crypto-token/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-psqueues/buildlink3.mk"
.include "../../devel/hs-serialise/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
