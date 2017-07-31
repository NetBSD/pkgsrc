# $NetBSD: buildlink3.mk,v 1.4 2017/07/31 14:18:20 taca Exp $

BUILDLINK_TREE+=	libgit2

.if !defined(LIBGIT2_BUILDLINK3_MK)
LIBGIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=0.26.0
BUILDLINK_PKGSRCDIR.libgit2?=	../../devel/libgit2

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.endif	# LIBGIT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgit2
