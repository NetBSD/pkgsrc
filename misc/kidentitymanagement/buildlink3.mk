# $NetBSD: buildlink3.mk,v 1.46 2026/09/02 19:03:31 wiz Exp $

BUILDLINK_TREE+=	kidentitymanagement

.if !defined(KIDENTITYMANAGEMENT_BUILDLINK3_MK)
KIDENTITYMANAGEMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kidentitymanagement+=	kidentitymanagement>=25.08.2
BUILDLINK_ABI_DEPENDS.kidentitymanagement?=	kidentitymanagement>=25.08.3nb7
BUILDLINK_PKGSRCDIR.kidentitymanagement?=	../../misc/kidentitymanagement

.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KIDENTITYMANAGEMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kidentitymanagement
