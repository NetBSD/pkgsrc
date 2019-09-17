# $NetBSD: buildlink3.mk,v 1.9 2019/09/17 23:09:42 perseant Exp $

BUILDLINK_TREE+=	pcsc-lite

.if !defined(PCSC_LITE_BUILDLINK3_MK)
PCSC_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcsc-lite+=	pcsc-lite>=1.8.3
BUILDLINK_PKGSRCDIR.pcsc-lite?=		../../security/pcsc-lite

.endif # PCSC_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcsc-lite
