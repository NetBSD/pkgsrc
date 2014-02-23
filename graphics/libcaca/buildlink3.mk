# $NetBSD: buildlink3.mk,v 1.3 2014/02/23 00:35:32 schmonz Exp $

BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libcaca?=	build

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.99.18
BUILDLINK_PKGSRCDIR.libcaca?=	../../graphics/libcaca
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
