# $NetBSD: buildlink3.mk,v 1.6 2024/02/28 07:19:22 wiz Exp $

BUILDLINK_TREE+=	openjpeg

.if !defined(OPENJPEG_BUILDLINK3_MK)
OPENJPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjpeg+=	openjpeg>=2.1.0
BUILDLINK_ABI_DEPENDS.openjpeg+=	openjpeg>=2.1.0
BUILDLINK_PKGSRCDIR.openjpeg?=		../../graphics/openjpeg

BUILDLINK_FILES.openjpeg+=	bin/opj_compress
BUILDLINK_FILES.openjpeg+=	bin/opj_decompress
BUILDLINK_FILES.openjpeg+=	bin/opj_dump

.endif	# OPENJPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjpeg
