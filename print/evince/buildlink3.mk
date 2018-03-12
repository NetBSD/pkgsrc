# $NetBSD: buildlink3.mk,v 1.30 2018/03/12 11:15:42 wiz Exp $

BUILDLINK_TREE+=	evince

.if !defined(EVINCE_BUILDLINK3_MK)
EVINCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evince+=	evince>=2.30.1<3
BUILDLINK_ABI_DEPENDS.evince+=	evince>=2.32.0nb64
BUILDLINK_PKGSRCDIR.evince?=	../../print/evince

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # EVINCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-evince
