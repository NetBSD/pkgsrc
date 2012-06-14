# $NetBSD: buildlink3.mk,v 1.5 2012/06/14 07:43:08 sbd Exp $

BUILDLINK_TREE+=	libplist

.if !defined(LIBPLIST_BUILDLINK3_MK)
LIBPLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplist+=	libplist>=1.8
BUILDLINK_ABI_DEPENDS.libplist?=	libplist>=1.8nb1
BUILDLINK_PKGSRCDIR.libplist?=	../../textproc/libplist

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBPLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplist
