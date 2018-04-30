# $NetBSD: buildlink3.mk,v 1.1 2018/04/30 16:51:54 bacon Exp $

BUILDLINK_TREE+=	htslib

.if !defined(HTSLIB_BUILDLINK3_MK)
HTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.htslib+=	htslib>=1.8
BUILDLINK_PKGSRCDIR.htslib?=	../../wip/htslib

.endif	# HTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-htslib
