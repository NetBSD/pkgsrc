# $NetBSD: buildlink3.mk,v 1.11 2013/01/26 21:36:44 adam Exp $

BUILDLINK_TREE+=	libspectre

.if !defined(LIBSPECTRE_BUILDLINK3_MK)
LIBSPECTRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspectre+=	libspectre>=0.2.1
BUILDLINK_ABI_DEPENDS.libspectre+=	libspectre>=0.2.7nb1
BUILDLINK_PKGSRCDIR.libspectre?=	../../print/libspectre

.include "../../print/ghostscript/buildlink3.mk"
.endif # LIBSPECTRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspectre
