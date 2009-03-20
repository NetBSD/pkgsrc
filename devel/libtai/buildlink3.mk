# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_TREE+=	libtai

.if !defined(LIBTAI_BUILDLINK3_MK)
LIBTAI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtai+=	libtai>=0.60nb1
BUILDLINK_PKGSRCDIR.libtai?=	../../devel/libtai
BUILDLINK_DEPMETHOD.libtai?=	build
.endif # LIBTAI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtai
