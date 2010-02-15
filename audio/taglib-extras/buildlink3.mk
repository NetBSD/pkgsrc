# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/15 15:39:08 wiz Exp $

BUILDLINK_TREE+=	taglib-extras

.if !defined(TAGLIB_EXTRAS_BUILDLINK3_MK)
TAGLIB_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib-extras+=	taglib-extras>=1.0.1
BUILDLINK_PKGSRCDIR.taglib-extras?=	../../audio/taglib-extras

.include "../../audio/taglib/buildlink3.mk"
.endif	# TAGLIB_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib-extras
