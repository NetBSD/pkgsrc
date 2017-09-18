# $NetBSD: buildlink3.mk,v 1.11 2017/09/18 09:53:03 maya Exp $

BUILDLINK_TREE+=	kxmlrpcclient

.if !defined(KXMLRPCCLIENT_BUILDLINK3_MK)
KXMLRPCCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kxmlrpcclient+=	kxmlrpcclient>=5.21.0
BUILDLINK_ABI_DEPENDS.kxmlrpcclient?=	kxmlrpcclient>=5.25.0nb10
BUILDLINK_PKGSRCDIR.kxmlrpcclient?=	../../net/kxmlrpcclient

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KXMLRPCCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kxmlrpcclient
