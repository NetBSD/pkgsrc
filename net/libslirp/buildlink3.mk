# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:25:01 wiz Exp $

BUILDLINK_TREE+=	libslirp

.if !defined(LIBSLIRP_BUILDLINK3_MK)
LIBSLIRP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslirp+=	libslirp>=4.3.1
BUILDLINK_ABI_DEPENDS.libslirp?=	libslirp>=4.7.0nb2
BUILDLINK_PKGSRCDIR.libslirp?=		../../net/libslirp

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBSLIRP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslirp
