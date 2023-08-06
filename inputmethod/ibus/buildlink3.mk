# $NetBSD: buildlink3.mk,v 1.10 2023/08/06 06:38:26 adam Exp $

BUILDLINK_TREE+=	ibus

.if !defined(IBUS_BUILDLINK3_MK)
IBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ibus+=	ibus>=1.5.0
BUILDLINK_ABI_DEPENDS.ibus+=	ibus>=1.5.25nb1
BUILDLINK_PKGSRCDIR.ibus?=	../../inputmethod/ibus

.include "../../devel/glib2/buildlink3.mk"
.endif	# IBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus
