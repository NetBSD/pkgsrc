# $NetBSD: buildlink3.mk,v 1.1 2014/04/18 12:38:22 wiz Exp $

BUILDLINK_TREE+=	libcuefile

.if !defined(LIBCUEFILE_BUILDLINK3_MK)
LIBCUEFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcuefile+=	libcuefile>=0rc475
BUILDLINK_PKGSRCDIR.libcuefile?=	../../audio/libcuefile
.endif	# LIBCUEFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcuefile
