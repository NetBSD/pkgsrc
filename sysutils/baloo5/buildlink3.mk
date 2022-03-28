# $NetBSD: buildlink3.mk,v 1.35 2022/03/28 10:59:28 tnn Exp $

BUILDLINK_TREE+=	baloo5

.if !defined(BALOO5_BUILDLINK3_MK)
BALOO5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo5+=	baloo5>=5.21.0
BUILDLINK_ABI_DEPENDS.baloo5?=	baloo5>=5.80.0nb5
BUILDLINK_PKGSRCDIR.baloo5?=	../../sysutils/baloo5

.include "../../databases/lmdb/buildlink3.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
#.include "../../devel/libinotify/buildlink3.mk"
.include "../../sysutils/kfilemetadata5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# BALOO5_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo5
