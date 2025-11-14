# $NetBSD: buildlink3.mk,v 1.1 2025/11/14 09:45:24 adam Exp $

BUILDLINK_TREE+=	libfyaml

.if !defined(LIBFYAML_BUILDLINK3_MK)
LIBFYAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfyaml+=	libfyaml>=0.9
BUILDLINK_PKGSRCDIR.libfyaml?=		../../textproc/libfyaml
.endif	# LIBFYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfyaml
