# $NetBSD: buildlink3.mk,v 1.17 2018/11/12 03:51:21 ryoon Exp $

BUILDLINK_TREE+=	kxmlrpcclient

.if !defined(KXMLRPCCLIENT_BUILDLINK3_MK)
KXMLRPCCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kxmlrpcclient+=	kxmlrpcclient>=5.21.0
BUILDLINK_ABI_DEPENDS.kxmlrpcclient?=	kxmlrpcclient>=5.47.0nb4
BUILDLINK_PKGSRCDIR.kxmlrpcclient?=	../../net/kxmlrpcclient

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KXMLRPCCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kxmlrpcclient
