# $NetBSD: buildlink3.mk,v 1.14 2023/08/14 05:23:54 wiz Exp $

BUILDLINK_TREE+=	libfolks

.if !defined(LIBFOLKS_BUILDLINK3_MK)
LIBFOLKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfolks+=	libfolks>=0.14.0
BUILDLINK_ABI_DEPENDS.libfolks+=	libfolks>=0.15.5nb7
BUILDLINK_PKGSRCDIR.libfolks?=		../../chat/libfolks

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.endif	# LIBFOLKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfolks
