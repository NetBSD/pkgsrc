# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/11/21 18:51:37 shattered Exp $

BUILDLINK_TREE+=	libplist

.if !defined(LIBPLIST_BUILDLINK3_MK)
LIBPLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplist+=	libplist>=1.3
BUILDLINK_PKGSRCDIR.libplist?=	../../textproc/libplist

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBPLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplist
