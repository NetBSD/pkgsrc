# $NetBSD: buildlink3.mk,v 1.12 2012/09/03 10:02:19 marino Exp $

BUILDLINK_TREE+=	taglib

.if !defined(TAGLIB_BUILDLINK3_MK)
TAGLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.0
BUILDLINK_ABI_DEPENDS.taglib+=	taglib>=1.3
BUILDLINK_PKGSRCDIR.taglib?=	../../audio/taglib
BUILDLINK_INCDIRS.taglib+=	include/taglib
.endif # TAGLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib
