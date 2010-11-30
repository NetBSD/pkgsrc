# $NetBSD: buildlink3.mk,v 1.1 2010/11/30 22:13:41 wiz Exp $

BUILDLINK_DEPMETHOD.libcaca?=	build
BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.9nb3
BUILDLINK_PKGSRCDIR.libcaca?=	../../graphics/libcaca
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
