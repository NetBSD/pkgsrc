# $NetBSD: buildlink3.mk,v 1.5 2016/10/10 06:36:36 wiz Exp $

BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.99.18
BUILDLINK_PKGSRCDIR.libcaca?=	../../graphics/libcaca

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
