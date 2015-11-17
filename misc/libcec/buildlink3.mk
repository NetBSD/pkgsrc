# $NetBSD: buildlink3.mk,v 1.1 2015/11/17 00:02:13 jmcneill Exp $

BUILDLINK_TREE+=	libcec

.if !defined(LIBCEC_BUILDLINK3_MK)
LIBCEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcec+=	libcec>=2.2.0
BUILDLINK_PKGSRCDIR.libcec?=	../../misc/libcec

.endif	# LIBCEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcec
