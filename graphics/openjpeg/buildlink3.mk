# $NetBSD: buildlink3.mk,v 1.5 2018/01/07 13:04:15 rillig Exp $

BUILDLINK_TREE+=	openjpeg

.if !defined(OPENJPEG_BUILDLINK3_MK)
OPENJPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjpeg+=	openjpeg>=2.1.0
BUILDLINK_ABI_DEPENDS.openjpeg+=	openjpeg>=2.1.0
BUILDLINK_PKGSRCDIR.openjpeg?=		../../graphics/openjpeg
.endif	# OPENJPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjpeg
