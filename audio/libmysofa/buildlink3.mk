# $NetBSD: buildlink3.mk,v 1.2 2020/02/08 16:34:55 nia Exp $

BUILDLINK_TREE+=	libmysofa

.if !defined(LIBMYSOFA_BUILDLINK3_MK)
LIBMYSOFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmysofa+=	libmysofa>=1.0
BUILDLINK_PKGSRCDIR.libmysofa?=		../../audio/libmysofa

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBMYSOFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmysofa
