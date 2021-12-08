# $NetBSD: buildlink3.mk,v 1.30 2021/12/08 16:02:32 adam Exp $

BUILDLINK_TREE+=	evince

.if !defined(EVINCE_BUILDLINK3_MK)
EVINCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evince+=	evince>=3.0
BUILDLINK_ABI_DEPENDS.evince+=	evince>=3.34.2nb16
BUILDLINK_PKGSRCDIR.evince?=	../../print/evince3

.include "../../x11/gtk3/buildlink3.mk"
.endif # EVINCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-evince
