# $NetBSD: buildlink3.mk,v 1.10 2020/11/05 09:07:10 ryoon Exp $

BUILDLINK_TREE+=	libplist

.if !defined(LIBPLIST_BUILDLINK3_MK)
LIBPLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplist+=	libplist>=1.8
BUILDLINK_ABI_DEPENDS.libplist+=	libplist>=1.12nb3
BUILDLINK_PKGSRCDIR.libplist?=		../../textproc/libplist

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBPLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplist
