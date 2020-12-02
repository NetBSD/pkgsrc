# $NetBSD: buildlink3.mk,v 1.1 2020/12/02 12:30:20 nia Exp $

BUILDLINK_TREE+=	libgig

.if !defined(LIBGIG_BUILDLINK3_MK)
LIBGIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgig+=	libgig>=4.2.0
BUILDLINK_PKGSRCDIR.libgig?=	../../audio/libgig
.endif	# LIBGIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgig
