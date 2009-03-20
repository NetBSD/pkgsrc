# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:16 joerg Exp $

BUILDLINK_TREE+=	libargparse

.if !defined(LIBARGPARSE_BUILDLINK3_MK)
LIBARGPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libargparse+=	libargparse>=0.1.0000
BUILDLINK_ABI_DEPENDS.libargparse+=	libargparse>=0.1.0000nb1
BUILDLINK_PKGSRCDIR.libargparse?=	../../devel/libargparse
.endif # LIBARGPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libargparse
