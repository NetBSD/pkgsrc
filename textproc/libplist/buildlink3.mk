# $NetBSD: buildlink3.mk,v 1.3 2012/03/03 00:12:03 wiz Exp $

BUILDLINK_TREE+=	libplist

.if !defined(LIBPLIST_BUILDLINK3_MK)
LIBPLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplist+=	libplist>=1.3
BUILDLINK_ABI_DEPENDS.libplist?=	libplist>=1.4nb3
BUILDLINK_PKGSRCDIR.libplist?=	../../textproc/libplist

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBPLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplist
