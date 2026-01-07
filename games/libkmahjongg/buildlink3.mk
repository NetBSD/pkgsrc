# $NetBSD: buildlink3.mk,v 1.29 2026/01/07 08:47:06 wiz Exp $

BUILDLINK_TREE+=	libkmahjongg

.if !defined(LIBKMAHJONGG_BUILDLINK3_MK)
LIBKMAHJONGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkmahjongg+=	libkmahjongg>=25.08.2
BUILDLINK_ABI_DEPENDS.libkmahjongg?=	libkmahjongg>=25.08.3nb1
BUILDLINK_PKGSRCDIR.libkmahjongg?=	../../games/libkmahjongg

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKMAHJONGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkmahjongg
