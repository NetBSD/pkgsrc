# $NetBSD: buildlink3.mk,v 1.1 2023/12/18 01:41:49 thor Exp $

BUILDLINK_TREE+=	libpll

.if !defined(LIBPLL_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpll+=	libpll>=0.3.2
BUILDLINK_PKGSRCDIR.libpll?=	../../biology/libpll

.endif	# LIBPLL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpll
