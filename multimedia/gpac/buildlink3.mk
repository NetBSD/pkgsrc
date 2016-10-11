# $NetBSD: buildlink3.mk,v 1.4 2016/10/11 00:31:28 tnn Exp $

BUILDLINK_TREE+=	gpac

.if !defined(GPAC_BUILDLINK3_MK)
GPAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpac+=	gpac>=0.6.0
BUILDLINK_ABI_DEPENDS.gpac+=	gpac>=0.6.0
BUILDLINK_PKGSRCDIR.gpac?=	../../multimedia/gpac
.endif # GPAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpac
