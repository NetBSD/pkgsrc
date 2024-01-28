# $NetBSD: buildlink3.mk,v 1.3 2024/01/28 13:24:35 wiz Exp $

BUILDLINK_TREE+=	taglib-extras

.if !defined(TAGLIB_EXTRAS_BUILDLINK3_MK)
TAGLIB_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib-extras+=	taglib-extras>=1.0.1
BUILDLINK_ABI_DEPENDS.taglib-extras?=	taglib-extras>=1.0.1nb2
BUILDLINK_PKGSRCDIR.taglib-extras?=	../../audio/taglib-extras

.include "../../audio/taglib/buildlink3.mk"
.endif	# TAGLIB_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib-extras
