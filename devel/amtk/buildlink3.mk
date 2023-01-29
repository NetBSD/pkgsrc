# $NetBSD: buildlink3.mk,v 1.7 2023/01/29 21:14:25 ryoon Exp $

BUILDLINK_TREE+=	amtk

.if !defined(AMTK_BUILDLINK3_MK)
AMTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.amtk+=	amtk>=5.0.0
BUILDLINK_ABI_DEPENDS.amtk?=	amtk>=5.0.2nb5
BUILDLINK_PKGSRCDIR.amtk?=	../../devel/amtk
BUILDLINK_INCDIRS.amtk+=	include/amtk-5

.include "../../x11/gtk3/buildlink3.mk"
.endif	# AMTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-amtk
