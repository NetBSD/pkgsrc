# $NetBSD: buildlink3.mk,v 1.2 2013/04/06 13:46:33 rodent Exp $

BUILDLINK_TREE+=	libcaca

.if !defined(LIBCACA_BUILDLINK3_MK)
LIBCACA_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libcaca?=	build

BUILDLINK_API_DEPENDS.libcaca+=	libcaca>=0.9nb3
BUILDLINK_PKGSRCDIR.libcaca?=	../../graphics/libcaca
.endif	# LIBCACA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaca
