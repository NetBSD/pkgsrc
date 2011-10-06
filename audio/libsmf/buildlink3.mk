# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/06 11:50:09 ryoon Exp $

BUILDLINK_TREE+=	libsmf

.if !defined(LIBSMF_BUILDLINK3_MK)
LIBSMF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsmf+=	libsmf>=1.3
BUILDLINK_PKGSRCDIR.libsmf?=	../../audio/libsmf

.endif	# LIBSMF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsmf
