# $NetBSD: buildlink3.mk,v 1.13 2013/10/17 07:56:39 wiz Exp $

BUILDLINK_TREE+=	taglib

.if !defined(TAGLIB_BUILDLINK3_MK)
TAGLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.0
BUILDLINK_ABI_DEPENDS.taglib+=	taglib>=1.9.1
BUILDLINK_PKGSRCDIR.taglib?=	../../audio/taglib
BUILDLINK_INCDIRS.taglib+=	include/taglib
.endif # TAGLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib
