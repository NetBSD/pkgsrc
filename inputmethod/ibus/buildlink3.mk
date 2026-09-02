# $NetBSD: buildlink3.mk,v 1.13 2026/09/02 19:03:04 wiz Exp $

BUILDLINK_TREE+=	ibus

.if !defined(IBUS_BUILDLINK3_MK)
IBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ibus+=	ibus>=1.5.0
BUILDLINK_ABI_DEPENDS.ibus+=	ibus>=1.5.34nb3
BUILDLINK_PKGSRCDIR.ibus?=	../../inputmethod/ibus

.include "../../devel/glib2/buildlink3.mk"
.endif	# IBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus
