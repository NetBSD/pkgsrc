# $NetBSD: buildlink3.mk,v 1.8 2018/01/07 13:04:30 rillig Exp $

BUILDLINK_TREE+=	pcsc-lite

.if !defined(PCSC_LITE_BUILDLINK3_MK)
PCSC_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcsc-lite+=	pcsc-lite>=1.6.5
BUILDLINK_PKGSRCDIR.pcsc-lite?=		../../security/pcsc-lite

.endif # PCSC_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcsc-lite
