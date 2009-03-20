# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:02 joerg Exp $

BUILDLINK_TREE+=	gpac

.if !defined(GPAC_BUILDLINK3_MK)
GPAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpac+=	gpac>=0.4.5
BUILDLINK_PKGSRCDIR.gpac?=	../../multimedia/gpac
.endif # GPAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpac
