# $NetBSD: buildlink3.mk,v 1.24 2023/05/06 19:08:52 ryoon Exp $

BUILDLINK_TREE+=	kidentitymanagement

.if !defined(KIDENTITYMANAGEMENT_BUILDLINK3_MK)
KIDENTITYMANAGEMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kidentitymanagement+=	kidentitymanagement>=17.12.1
BUILDLINK_ABI_DEPENDS.kidentitymanagement?=	kidentitymanagement>=22.08.1nb5
BUILDLINK_PKGSRCDIR.kidentitymanagement?=	../../misc/kidentitymanagement

.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KIDENTITYMANAGEMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kidentitymanagement
