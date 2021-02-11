# $NetBSD: buildlink3.mk,v 1.1 2021/02/11 19:54:07 markd Exp $

BUILDLINK_TREE+=	kdsoap

.if !defined(KDSOAP_BUILDLINK3_MK)
KDSOAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsoap+=	kdsoap>=1.9.1
BUILDLINK_PKGSRCDIR.kdsoap?=	../../net/kdsoap

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDSOAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsoap
