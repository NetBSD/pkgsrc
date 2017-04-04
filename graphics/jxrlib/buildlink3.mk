# $NetBSD: buildlink3.mk,v 1.1 2017/04/04 13:07:07 wiz Exp $

BUILDLINK_TREE+=	jxrlib

.if !defined(JXRLIB_BUILDLINK3_MK)
JXRLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jxrlib+=	jxrlib>=1.1
BUILDLINK_PKGSRCDIR.jxrlib?=	../../graphics/jxrlib
BUILDLINK_DEPMETHOD.jxrlib?=	build
.endif	# JXRLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-jxrlib
