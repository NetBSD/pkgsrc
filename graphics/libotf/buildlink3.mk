# $NetBSD: buildlink3.mk,v 1.8 2023/11/12 13:22:07 wiz Exp $

BUILDLINK_TREE+=	libotf

.if !defined(LIBOTF_BUILDLINK3_MK)
LIBOTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libotf+=	libotf>=0.9.7
BUILDLINK_ABI_DEPENDS.libotf+=	libotf>=0.9.16nb4
BUILDLINK_PKGSRCDIR.libotf?=	../../graphics/libotf

.include "../../graphics/freetype2/buildlink3.mk"
.endif # LIBOTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libotf
