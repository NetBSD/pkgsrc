# $NetBSD: buildlink3.mk,v 1.2 2025/09/08 08:22:16 vins Exp $

BUILDLINK_TREE+=	libgrapheme

.if !defined(LIBGRAPHEME_BUILDLINK3_MK)
LIBGRAPHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgrapheme+=	libgrapheme>=2.0.2p1
BUILDLINK_PKGSRCDIR.libgrapheme?=	../../textproc/libgrapheme
.endif	# LIBGRAPHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgrapheme
