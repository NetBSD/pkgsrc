# $NetBSD: buildlink3.mk,v 1.1 2017/02/04 01:38:36 ryoon Exp $

BUILDLINK_TREE+=	libzmf

.if !defined(LIBZMF_BUILDLINK3_MK)
LIBZMF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzmf+=	libzmf>=0.0.1
BUILDLINK_PKGSRCDIR.libzmf?=	../../converters/libzmf

.endif	# LIBZMF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzmf
