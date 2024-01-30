# $NetBSD: buildlink3.mk,v 1.1 2024/01/30 09:00:40 wiz Exp $

BUILDLINK_TREE+=	sonic

.if !defined(SONIC_BUILDLINK3_MK)
SONIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sonic+=	sonic>=0.0.0.225
BUILDLINK_ABI_DEPENDS.sonic+=	sonic>=0.0.0.225
BUILDLINK_PKGSRCDIR.sonic?=	../../audio/sonic

.endif # SONIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-sonic
