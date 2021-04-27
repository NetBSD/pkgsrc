# $NetBSD: buildlink3.mk,v 1.1 2021/04/27 22:58:40 thor Exp $

BUILDLINK_TREE+=	metslib

.if !defined(METSLIB_BUILDLINK3_MK)
METSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.metslib+=	metslib>=0.5.3
BUILDLINK_PKGSRCDIR.metslib?=	../../devel/metslib
.endif	# METSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-metslib
