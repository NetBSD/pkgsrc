# $NetBSD: buildlink3.mk,v 1.3 2022/04/18 19:10:02 adam Exp $

BUILDLINK_TREE+=	kdsoap

.if !defined(KDSOAP_BUILDLINK3_MK)
KDSOAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsoap+=	kdsoap>=1.9.1
BUILDLINK_ABI_DEPENDS.kdsoap?=	kdsoap>=1.9.1nb3
BUILDLINK_PKGSRCDIR.kdsoap?=	../../net/kdsoap

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDSOAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsoap
