# $NetBSD: buildlink3.mk,v 1.6 2023/08/14 05:24:35 wiz Exp $

BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.99.18
BUILDLINK_ABI_DEPENDS.libcaca?=	libcaca>=0.99.19nb2
BUILDLINK_PKGSRCDIR.libcaca?=	../../graphics/libcaca

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
