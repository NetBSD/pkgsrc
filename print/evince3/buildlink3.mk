# $NetBSD: buildlink3.mk,v 1.27 2020/03/08 16:48:05 wiz Exp $

BUILDLINK_TREE+=	evince

.if !defined(EVINCE_BUILDLINK3_MK)
EVINCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evince+=	evince>=3.0
BUILDLINK_ABI_DEPENDS.evince+=	evince>=3.34.2nb2
BUILDLINK_PKGSRCDIR.evince?=	../../print/evince3

.include "../../x11/gtk3/buildlink3.mk"
.endif # EVINCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-evince
