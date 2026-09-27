# $NetBSD: buildlink3.mk,v 1.7 2026/09/27 11:38:06 tnn Exp $

BUILDLINK_TREE+=	libslirp

.if !defined(LIBSLIRP_BUILDLINK3_MK)
LIBSLIRP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslirp+=	libslirp>=4.3.1
BUILDLINK_ABI_DEPENDS.libslirp?=	libslirp>=4.9.3nb2
BUILDLINK_PKGSRCDIR.libslirp?=		../../net/libslirp

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBSLIRP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslirp
