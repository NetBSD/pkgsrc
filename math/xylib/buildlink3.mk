# $NetBSD: buildlink3.mk,v 1.3 2012/05/07 01:53:47 dholland Exp $

BUILDLINK_TREE+=	xylib

.if !defined(XYLIB_BUILDLINK3_MK)
XYLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xylib+=	xylib>=0.4
BUILDLINK_ABI_DEPENDS.xylib+=	xylib>=0.8nb1
BUILDLINK_PKGSRCDIR.xylib?=	../../math/xylib

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif	# XYLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xylib
