# $NetBSD: buildlink3.mk,v 1.17 2016/08/03 10:22:17 adam Exp $

BUILDLINK_TREE+=	evince

.if !defined(EVINCE_BUILDLINK3_MK)
EVINCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evince+=	evince>=3.0
BUILDLINK_ABI_DEPENDS.evince+=	evince>=3.20.0nb5
BUILDLINK_PKGSRCDIR.evince?=	../../print/evince

.include "../../x11/gtk3/buildlink3.mk"
.endif # EVINCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-evince
