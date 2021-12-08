# $NetBSD: buildlink3.mk,v 1.2 2021/12/08 16:02:29 adam Exp $

BUILDLINK_TREE+=	libslirp

.if !defined(LIBSLIRP_BUILDLINK3_MK)
LIBSLIRP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslirp+=	libslirp>=4.3.1
BUILDLINK_ABI_DEPENDS.libslirp?=		libslirp>=4.3.1
BUILDLINK_PKGSRCDIR.libslirp?=		../../net/libslirp

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBSLIRP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslirp
