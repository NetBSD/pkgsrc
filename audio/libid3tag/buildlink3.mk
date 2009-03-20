# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:55 joerg Exp $

BUILDLINK_TREE+=	libid3tag

.if !defined(LIBID3TAG_BUILDLINK3_MK)
LIBID3TAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libid3tag+=	libid3tag>=0.15.0b
BUILDLINK_ABI_DEPENDS.libid3tag+=	libid3tag>=0.15.1bnb1
BUILDLINK_PKGSRCDIR.libid3tag?=	../../audio/libid3tag

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBID3TAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libid3tag
