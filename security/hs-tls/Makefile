# $NetBSD: Makefile,v 1.16 2025/01/30 11:10:36 pho Exp $

DISTNAME=	tls-2.1.7
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	TLS/SSL protocol native implementation (Server and Client)
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f-devel

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-crypton-x509/buildlink3.mk"
.include "../../security/hs-crypton-x509-store/buildlink3.mk"
.include "../../security/hs-crypton-x509-validation/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-serialise/buildlink3.mk"
.include "../../time/hs-unix-time/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
