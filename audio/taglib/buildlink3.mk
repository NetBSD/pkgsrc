# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:23:59 joerg Exp $

BUILDLINK_TREE+=	taglib

.if !defined(TAGLIB_BUILDLINK3_MK)
TAGLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.0
BUILDLINK_ABI_DEPENDS.taglib+=	taglib>=1.3
BUILDLINK_PKGSRCDIR.taglib?=	../../audio/taglib
.endif # TAGLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib
