# $NetBSD: Makefile,v 1.3 2022/01/18 02:48:21 pho Exp $

DISTNAME=	x509-1.7.5
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	X509 reader and writer
LICENSE=	modified-bsd

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-parse/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
