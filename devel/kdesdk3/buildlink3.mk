# $NetBSD: buildlink3.mk,v 1.24 2010/01/18 09:58:45 wiz Exp $

BUILDLINK_TREE+=	kdesdk

.if !defined(KDESDK_BUILDLINK3_MK)
KDESDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdesdk+=	kdesdk>=3.5.0nb1
BUILDLINK_ABI_DEPENDS.kdesdk?=	kdesdk>=3.5.10nb6
BUILDLINK_PKGSRCDIR.kdesdk?=	../../devel/kdesdk3

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.endif # KDESDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdesdk
