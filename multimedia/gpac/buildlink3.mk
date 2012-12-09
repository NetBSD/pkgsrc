# $NetBSD: buildlink3.mk,v 1.3 2012/12/09 17:15:06 ryoon Exp $

BUILDLINK_TREE+=	gpac

.if !defined(GPAC_BUILDLINK3_MK)
GPAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpac+=	gpac>=0.5.0
BUILDLINK_ABI_DEPENDS.gpac+=	gpac>=0.5.0
BUILDLINK_PKGSRCDIR.gpac?=	../../multimedia/gpac
.endif # GPAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpac
