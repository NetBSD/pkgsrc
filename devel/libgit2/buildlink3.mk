# $NetBSD: buildlink3.mk,v 1.6 2019/02/24 10:15:26 wiz Exp $

BUILDLINK_TREE+=	libgit2

.if !defined(LIBGIT2_BUILDLINK3_MK)
LIBGIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=0.26.0
BUILDLINK_ABI_DEPENDS.libgit2+=	libgit2>=0.28.0
BUILDLINK_PKGSRCDIR.libgit2?=	../../devel/libgit2

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBGIT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgit2
