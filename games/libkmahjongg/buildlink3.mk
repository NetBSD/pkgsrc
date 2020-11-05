# $NetBSD: buildlink3.mk,v 1.9 2020/11/05 09:06:52 ryoon Exp $

BUILDLINK_TREE+=	libkmahjongg

.if !defined(LIBKMAHJONGG_BUILDLINK3_MK)
LIBKMAHJONGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkmahjongg+=	libkmahjongg>=19.08.3
BUILDLINK_ABI_DEPENDS.libkmahjongg?=	libkmahjongg>=20.04.1nb2
BUILDLINK_PKGSRCDIR.libkmahjongg?=	../../games/libkmahjongg

.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif	# LIBKMAHJONGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkmahjongg
