# $NetBSD: buildlink3.mk,v 1.3 2025/09/08 08:26:18 vins Exp $

BUILDLINK_TREE+=	libgrapheme

.if !defined(LIBGRAPHEME_BUILDLINK3_MK)
LIBGRAPHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgrapheme+=	libgrapheme>=2.0.2nb1
BUILDLINK_PKGSRCDIR.libgrapheme?=	../../textproc/libgrapheme
.endif	# LIBGRAPHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgrapheme
