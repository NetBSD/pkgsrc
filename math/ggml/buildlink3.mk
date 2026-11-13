# $NetBSD: buildlink3.mk,v 1.2 2026/11/13 15:05:52 wiz Exp $

BUILDLINK_TREE+=	ggml

.if !defined(GGML_BUILDLINK3_MK)
GGML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ggml+=	ggml>=0.15.3
BUILDLINK_ABI_DEPENDS.ggml+=	ggml>=1.0.0
BUILDLINK_PKGSRCDIR.ggml?=	../../math/ggml

.endif	# GGML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ggml
