# $NetBSD: buildlink3.mk,v 1.11 2020/06/10 18:08:21 nia Exp $

BUILDLINK_TREE+=	libfolks

.if !defined(LIBFOLKS_BUILDLINK3_MK)
LIBFOLKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfolks+=	libfolks>=0.14.0
BUILDLINK_ABI_DEPENDS.libfolks+=	libfolks>=0.14.0
BUILDLINK_PKGSRCDIR.libfolks?=		../../chat/libfolks

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.endif	# LIBFOLKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfolks
