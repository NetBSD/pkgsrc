# $NetBSD: buildlink3.mk,v 1.5 2020/01/05 04:11:15 ryoon Exp $

BUILDLINK_TREE+=	gpac

.if !defined(GPAC_BUILDLINK3_MK)
GPAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpac+=	gpac>=0.8.0
BUILDLINK_ABI_DEPENDS.gpac+=	gpac>=0.8.0
BUILDLINK_PKGSRCDIR.gpac?=	../../multimedia/gpac
.endif # GPAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpac
