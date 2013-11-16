# $NetBSD: buildlink3.mk,v 1.1 2013/11/16 07:34:24 shattered Exp $

BUILDLINK_TREE+=	libxmp

.if !defined(LIBXMP_BUILDLINK3_MK)
LIBXMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmp+=	libxmp>=4.1.5
BUILDLINK_PKGSRCDIR.libxmp?=	../../audio/libxmp
.endif	# LIBXMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmp
