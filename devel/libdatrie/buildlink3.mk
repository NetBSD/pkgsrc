# $NetBSD: buildlink3.mk,v 1.6 2021/01/29 18:33:09 scole Exp $

BUILDLINK_TREE+=	libdatrie

.if !defined(LIBDATRIE_BUILDLINK3_MK)
LIBDATRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdatrie+=	libdatrie>=0.2.13
BUILDLINK_PKGSRCDIR.libdatrie?=		../../devel/libdatrie
.endif # LIBDATRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdatrie
