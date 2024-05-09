# $NetBSD: buildlink3.mk,v 1.15 2024/05/09 01:32:34 pho Exp $

BUILDLINK_TREE+=	hs-tls

.if !defined(HS_TLS_BUILDLINK3_MK)
HS_TLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tls+=	hs-tls>=2.0.5
BUILDLINK_ABI_DEPENDS.hs-tls+=	hs-tls>=2.0.5nb1
BUILDLINK_PKGSRCDIR.hs-tls?=	../../security/hs-tls

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-crypton-x509/buildlink3.mk"
.include "../../security/hs-crypton-x509-store/buildlink3.mk"
.include "../../security/hs-crypton-x509-validation/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-serialise/buildlink3.mk"
.include "../../time/hs-unix-time/buildlink3.mk"
.endif	# HS_TLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tls
