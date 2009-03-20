# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_TREE+=	libtecla

.if !defined(LIBTECLA_BUILDLINK3_MK)
LIBTECLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtecla+=	libtecla>=1.5.0
BUILDLINK_ABI_DEPENDS.libtecla?=	libtecla>=1.6.1nb1
BUILDLINK_PKGSRCDIR.libtecla?=	../../devel/libtecla
.endif # LIBTECLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtecla
