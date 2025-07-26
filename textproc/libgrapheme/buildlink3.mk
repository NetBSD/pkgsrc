# $NetBSD: buildlink3.mk,v 1.1 2025/07/26 06:36:33 vins Exp $

BUILDLINK_TREE+=	libgrapheme

.if !defined(LIBGRAPHEME_BUILDLINK3_MK)
LIBGRAPHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgrapheme+=	libgrapheme>=2.0.2
BUILDLINK_PKGSRCDIR.libgrapheme?=	../../textproc/libgrapheme
.endif	# LIBGRAPHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgrapheme
