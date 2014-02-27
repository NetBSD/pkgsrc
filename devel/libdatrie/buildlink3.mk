# $NetBSD: buildlink3.mk,v 1.4 2014/02/27 12:42:05 obache Exp $

BUILDLINK_TREE+=	libdatrie

.if !defined(LIBDATRIE_BUILDLINK3_MK)
LIBDATRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdatrie+=	libdatrie>=0.2.0
BUILDLINK_ABI_DEPENDS.libdatrie+=	libdatrie>=0.2.7.1
BUILDLINK_PKGSRCDIR.libdatrie?=	../../devel/libdatrie
.endif # LIBDATRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdatrie
