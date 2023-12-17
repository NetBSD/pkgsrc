# $NetBSD: buildlink3.mk,v 1.10 2023/12/17 13:59:38 nros Exp $

BUILDLINK_TREE+=	libtecla

.if !defined(LIBTECLA_BUILDLINK3_MK)
LIBTECLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtecla+=	libtecla>=1.5.0
BUILDLINK_ABI_DEPENDS.libtecla+=	libtecla>=1.6.3
BUILDLINK_PKGSRCDIR.libtecla?=		../../devel/libtecla
.endif # LIBTECLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtecla
