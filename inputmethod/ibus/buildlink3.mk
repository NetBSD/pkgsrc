# $NetBSD: buildlink3.mk,v 1.8 2020/03/08 16:47:51 wiz Exp $
#

BUILDLINK_TREE+=	ibus

.if !defined(IBUS_BUILDLINK3_MK)
IBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ibus+=	ibus>=1.5.0
BUILDLINK_ABI_DEPENDS.ibus?=	ibus>=1.5.21nb2
BUILDLINK_PKGSRCDIR.ibus?=	../../inputmethod/ibus

.include "../../devel/glib2/buildlink3.mk"
.endif	# IBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus
