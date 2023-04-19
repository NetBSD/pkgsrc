# $NetBSD: buildlink3.mk,v 1.15 2023/04/19 08:08:46 adam Exp $

BUILDLINK_TREE+=	libplist

.if !defined(LIBPLIST_BUILDLINK3_MK)
LIBPLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplist+=	libplist>=1.8
BUILDLINK_ABI_DEPENDS.libplist+=	libplist>=2.2.0nb3
BUILDLINK_PKGSRCDIR.libplist?=		../../textproc/libplist

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBPLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplist
