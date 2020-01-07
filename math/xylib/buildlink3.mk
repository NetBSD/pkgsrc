# $NetBSD: buildlink3.mk,v 1.4 2020/01/07 13:03:50 nros Exp $

BUILDLINK_TREE+=	xylib

.if !defined(XYLIB_BUILDLINK3_MK)
XYLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xylib+=	xylib>=0.4
BUILDLINK_ABI_DEPENDS.xylib+=	xylib>=1.5
BUILDLINK_PKGSRCDIR.xylib?=	../../math/xylib

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif	# XYLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xylib
