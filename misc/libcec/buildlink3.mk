# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:53 wiz Exp $

BUILDLINK_TREE+=	libcec

.if !defined(LIBCEC_BUILDLINK3_MK)
LIBCEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcec+=	libcec>=2.2.0
BUILDLINK_ABI_DEPENDS.libcec?=	libcec>=4.0.4nb3
BUILDLINK_PKGSRCDIR.libcec?=	../../misc/libcec

.endif	# LIBCEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcec
