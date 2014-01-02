# $NetBSD: buildlink3.mk,v 1.3 2014/01/02 14:43:21 ryoon Exp $

BUILDLINK_TREE+=	libopus

.if !defined(LIBOPUS_BUILDLINK3_MK)
LIBOPUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopus+=	libopus>=1.1
BUILDLINK_PKGSRCDIR.libopus?=	../../audio/libopus
.endif	# LIBOPUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopus
