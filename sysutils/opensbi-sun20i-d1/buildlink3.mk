# $NetBSD: buildlink3.mk,v 1.1 2024/07/18 08:51:14 rxg Exp $

BUILDLINK_TREE+=	opensbi-sun20i-d1

.if !defined(OPENSBI_SUN20I_D1_BUILDLINK3_MK)
OPENSBI_SUN20I_D1_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.opensbi-sun20i-d1?=		build
BUILDLINK_API_DEPENDS.opensbi-sun20i-d1+=	opensbi-sun20i-d1>=1.4
BUILDLINK_PKGSRCDIR.opensbi-sun20i-d1?=		../../sysutils/opensbi-sun20i-d1
.endif	# OPENSBI_SUN20I_D1_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensbi-sun20i-d1
