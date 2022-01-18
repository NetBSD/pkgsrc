# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:21 pho Exp $

BUILDLINK_TREE+=	hs-hackage-security

.if !defined(HS_HACKAGE_SECURITY_BUILDLINK3_MK)
HS_HACKAGE_SECURITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hackage-security+=	hs-hackage-security>=0.6.0
BUILDLINK_ABI_DEPENDS.hs-hackage-security+=	hs-hackage-security>=0.6.0.1nb2
BUILDLINK_PKGSRCDIR.hs-hackage-security?=	../../security/hs-hackage-security

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../security/hs-cryptohash-sha256/buildlink3.mk"
.include "../../security/hs-ed25519/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../devel/hs-lukko/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_HACKAGE_SECURITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hackage-security
