# $NetBSD: buildlink3.mk,v 1.18 2025/12/30 02:18:47 markd Exp $

BUILDLINK_TREE+=	kdsoap

.if !defined(KDSOAP_BUILDLINK3_MK)
KDSOAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsoap+=	kdsoap>=2.2.0
BUILDLINK_ABI_DEPENDS.kdsoap?=	kdsoap>=2.2.0
BUILDLINK_PKGSRCDIR.kdsoap?=	../../net/kdsoap

BUILDLINK_FILES.kdsoap+=	bin/kdwsdl2cpp-qt6

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDSOAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsoap
