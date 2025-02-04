# $NetBSD: buildlink3.mk,v 1.1 2025/02/04 02:16:46 gutteridge Exp $

BUILDLINK_TREE+=	opensbi-hifive-unleashed

.if !defined(OPENSBI_HIFIVE_UNLEASHED_BUILDLINK3_MK)
OPENSBI_HIFIVE_UNLEASHED_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.opensbi-hifive-unleashed?=		build
BUILDLINK_API_DEPENDS.opensbi-hifive-unleashed+=	opensbi-hifive-unleashed>=1.4
BUILDLINK_PKGSRCDIR.opensbi-hifive-unleashed?=		../../sysutils/opensbi-hifive-unleashed
.endif	# OPENSBI_HIFIVE_UNLEASHED_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensbi-hifive-unleashed
