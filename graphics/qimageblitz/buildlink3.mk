# $NetBSD: buildlink3.mk,v 1.9 2011/04/22 13:42:37 obache Exp $

BUILDLINK_TREE+=	qimageblitz

.if !defined(QIMAGEBLITZ_BUILDLINK3_MK)
QIMAGEBLITZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qimageblitz+=	qimageblitz>=0.0.4
BUILDLINK_ABI_DEPENDS.qimageblitz?=	qimageblitz>=0.0.6nb3
BUILDLINK_PKGSRCDIR.qimageblitz?=	../../graphics/qimageblitz

.include "../../x11/qt4-libs/buildlink3.mk"
.endif # QIMAGEBLITZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-qimageblitz
