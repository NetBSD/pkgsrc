# $NetBSD: buildlink3.mk,v 1.2 2024/01/24 16:36:38 wiz Exp $

BUILDLINK_TREE+=	libpll

.if !defined(LIBPLL_BUILDLINK3_MK)
LIBPLL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpll+=	libpll>=0.3.2
BUILDLINK_PKGSRCDIR.libpll?=	../../biology/libpll
.endif	# LIBPLL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpll
