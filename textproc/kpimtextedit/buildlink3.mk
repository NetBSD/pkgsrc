# $NetBSD: buildlink3.mk,v 1.41 2026/01/07 08:49:04 wiz Exp $

BUILDLINK_TREE+=	kpimtextedit

.if !defined(KPIMTEXTEDIT_BUILDLINK3_MK)
KPIMTEXTEDIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpimtextedit+=	kpimtextedit>=25.08.2
BUILDLINK_ABI_DEPENDS.kpimtextedit?=	kpimtextedit>=25.08.3nb1
BUILDLINK_PKGSRCDIR.kpimtextedit?=	../../textproc/kpimtextedit

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../textproc/kf6-syntax-highlighting/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KPIMTEXTEDIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpimtextedit
