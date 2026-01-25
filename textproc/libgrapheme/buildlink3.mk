# $NetBSD: buildlink3.mk,v 1.4 2026/01/25 16:10:19 vins Exp $

BUILDLINK_TREE+=	libgrapheme

.if !defined(LIBGRAPHEME_BUILDLINK3_MK)
LIBGRAPHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgrapheme+=	libgrapheme>=2.0.2nb1
BUILDLINK_API_DEPENDS.libgrapheme+=	libgrapheme>=3.0.0
BUILDLINK_PKGSRCDIR.libgrapheme?=	../../textproc/libgrapheme
.endif	# LIBGRAPHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgrapheme
