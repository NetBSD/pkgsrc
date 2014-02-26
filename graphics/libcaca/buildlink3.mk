# $NetBSD: buildlink3.mk,v 1.4 2014/02/26 10:34:30 wiedi Exp $

BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libcaca?=	build

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.99.18
BUILDLINK_PKGSRCDIR.libcaca?=	../../graphics/libcaca

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
