# $NetBSD: buildlink3.mk,v 1.33 2020/08/17 20:17:40 leot Exp $

BUILDLINK_TREE+=	libspectre

.if !defined(LIBSPECTRE_BUILDLINK3_MK)
LIBSPECTRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspectre+=	libspectre>=0.2.1
BUILDLINK_ABI_DEPENDS.libspectre+=	libspectre>=0.2.9nb1
BUILDLINK_PKGSRCDIR.libspectre?=	../../print/libspectre

.include "../../print/ghostscript-agpl/buildlink3.mk"
.endif # LIBSPECTRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspectre
