# $NetBSD: buildlink3.mk,v 1.2 2023/09/29 18:29:29 nros Exp $

BUILDLINK_TREE+=	libpgf

.if !defined(LIBPGF_BUILDLINK3_MK)
LIBPGF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpgf+=	libpgf>=7.21.7
BUILDLINK_PKGSRCDIR.libpgf?=	../../graphics/libpgf
.endif	# LIBPGF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpgf
