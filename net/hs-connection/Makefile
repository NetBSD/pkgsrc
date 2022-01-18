# $NetBSD: Makefile,v 1.3 2022/01/18 02:48:19 pho Exp $

DISTNAME=	connection-0.3.1
PKGREVISION=	2
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Network connection with optional TLS and/or SOCKS
LICENSE=	modified-bsd

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-socks/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../security/hs-x509-store/buildlink3.mk"
.include "../../security/hs-x509-system/buildlink3.mk"
.include "../../security/hs-x509-validation/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
