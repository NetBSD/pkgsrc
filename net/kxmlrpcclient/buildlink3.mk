# $NetBSD: buildlink3.mk,v 1.22 2020/03/08 16:48:02 wiz Exp $

BUILDLINK_TREE+=	kxmlrpcclient

.if !defined(KXMLRPCCLIENT_BUILDLINK3_MK)
KXMLRPCCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kxmlrpcclient+=	kxmlrpcclient>=5.21.0
BUILDLINK_ABI_DEPENDS.kxmlrpcclient?=	kxmlrpcclient>=5.66.0nb1
BUILDLINK_PKGSRCDIR.kxmlrpcclient?=	../../net/kxmlrpcclient

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KXMLRPCCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kxmlrpcclient
