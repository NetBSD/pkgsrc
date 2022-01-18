# $NetBSD: Makefile,v 1.3 2022/01/18 02:48:22 pho Exp $

DISTNAME=	x509-validation-1.6.11
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	X.509 Certificate and CRL validation
LICENSE=	modified-bsd

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../security/hs-x509-store/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
