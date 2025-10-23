# $NetBSD: buildlink3.mk,v 1.17 2025/10/23 20:38:48 wiz Exp $

BUILDLINK_TREE+=	kdsoap

.if !defined(KDSOAP_BUILDLINK3_MK)
KDSOAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsoap+=	kdsoap>=1.9.1
BUILDLINK_ABI_DEPENDS.kdsoap?=	kdsoap>=1.9.1nb19
BUILDLINK_PKGSRCDIR.kdsoap?=	../../net/kdsoap

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDSOAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsoap
