# $NetBSD: buildlink3.mk,v 1.3 2009/05/15 08:52:42 obache Exp $

BUILDLINK_TREE+=	libdatrie

.if !defined(LIBDATRIE_BUILDLINK3_MK)
LIBDATRIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdatrie+=	libdatrie>=0.2.0
BUILDLINK_PKGSRCDIR.libdatrie?=	../../devel/libdatrie
.endif # LIBDATRIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdatrie
