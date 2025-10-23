# $NetBSD: buildlink3.mk,v 1.15 2025/10/23 20:36:30 wiz Exp $

BUILDLINK_TREE+=	libgit2

.if !defined(LIBGIT2_BUILDLINK3_MK)
LIBGIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=0.28.0
BUILDLINK_ABI_DEPENDS.libgit2+=	libgit2>=1.9.1nb2
BUILDLINK_PKGSRCDIR.libgit2?=	../../devel/libgit2

.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBGIT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgit2
