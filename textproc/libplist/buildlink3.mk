# $NetBSD: buildlink3.mk,v 1.21 2025/04/17 21:52:35 wiz Exp $

BUILDLINK_TREE+=	libplist

.if !defined(LIBPLIST_BUILDLINK3_MK)
LIBPLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplist+=	libplist>=1.8
BUILDLINK_ABI_DEPENDS.libplist+=	libplist>=2.2.0nb10
BUILDLINK_PKGSRCDIR.libplist?=		../../textproc/libplist

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBPLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplist
