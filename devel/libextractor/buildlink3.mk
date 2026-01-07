# $NetBSD: buildlink3.mk,v 1.38 2026/01/07 08:46:40 wiz Exp $

BUILDLINK_TREE+=	libextractor

.if !defined(LIBEXTRACTOR_BUILDLINK3_MK)
LIBEXTRACTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libextractor+=	libextractor>=0.3.10
BUILDLINK_ABI_DEPENDS.libextractor+=	libextractor>=1.13nb21
BUILDLINK_PKGSRCDIR.libextractor?=	../../devel/libextractor

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.endif # LIBEXTRACTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libextractor
