# $NetBSD: buildlink3.mk,v 1.1 2026/07/02 10:58:21 wiz Exp $

BUILDLINK_TREE+=	ggml

.if !defined(GGML_BUILDLINK3_MK)
GGML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ggml+=	ggml>=0.15.3
BUILDLINK_PKGSRCDIR.ggml?=	../../math/ggml

.endif	# GGML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ggml
