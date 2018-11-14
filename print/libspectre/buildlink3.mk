# $NetBSD: buildlink3.mk,v 1.26 2018/11/14 22:22:18 kleink Exp $

BUILDLINK_TREE+=	libspectre

.if !defined(LIBSPECTRE_BUILDLINK3_MK)
LIBSPECTRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspectre+=	libspectre>=0.2.1
BUILDLINK_ABI_DEPENDS.libspectre+=	libspectre>=0.2.8nb7
BUILDLINK_PKGSRCDIR.libspectre?=	../../print/libspectre

.include "../../print/ghostscript/buildlink3.mk"
.endif # LIBSPECTRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspectre
