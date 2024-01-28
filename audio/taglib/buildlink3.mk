# $NetBSD: buildlink3.mk,v 1.14 2024/01/28 13:24:32 wiz Exp $

BUILDLINK_TREE+=	taglib

.if !defined(TAGLIB_BUILDLINK3_MK)
TAGLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.0
BUILDLINK_ABI_DEPENDS.taglib+=	taglib>=2.0
BUILDLINK_PKGSRCDIR.taglib?=	../../audio/taglib
BUILDLINK_INCDIRS.taglib+=	include/taglib
.endif # TAGLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib
