# $NetBSD: Makefile,v 1.7 2022/09/07 06:50:50 pho Exp $

DISTNAME=	x509-store-1.6.9
PKGREVISION=	3
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	X.509 collection accessing and storing methods
LICENSE=	modified-bsd

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
