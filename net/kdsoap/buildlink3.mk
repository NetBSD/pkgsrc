# $NetBSD: buildlink3.mk,v 1.2 2021/04/21 11:40:34 adam Exp $

BUILDLINK_TREE+=	kdsoap

.if !defined(KDSOAP_BUILDLINK3_MK)
KDSOAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsoap+=	kdsoap>=1.9.1
BUILDLINK_ABI_DEPENDS.kdsoap?=	kdsoap>=1.9.1nb1
BUILDLINK_PKGSRCDIR.kdsoap?=	../../net/kdsoap

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDSOAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsoap
