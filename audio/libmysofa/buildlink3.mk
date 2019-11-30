# $NetBSD: buildlink3.mk,v 1.1 2019/11/30 13:35:42 nia Exp $

BUILDLINK_TREE+=	libmysofa

.if !defined(LIBMYSOFA_BUILDLINK3_MK)
LIBMYSOFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmysofa+=	libmysofa>=0.9
BUILDLINK_PKGSRCDIR.libmysofa?=		../../audio/libmysofa

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBMYSOFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmysofa
