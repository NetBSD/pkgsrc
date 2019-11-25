# $NetBSD: buildlink3.mk,v 1.2 2019/11/25 21:07:18 nros Exp $

BUILDLINK_TREE+=	jxrlib

.if !defined(JXRLIB_BUILDLINK3_MK)
JXRLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jxrlib+=	jxrlib>=1.1
BUILDLINK_ABI_DEPENDS.jxrlib+=	jxrlib>=1.1nb1
BUILDLINK_PKGSRCDIR.jxrlib?=	../../graphics/jxrlib
BUILDLINK_DEPMETHOD.jxrlib?=	build
.endif	# JXRLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-jxrlib
