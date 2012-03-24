# $NetBSD: buildlink3.mk,v 1.2 2012/03/24 13:25:01 drochner Exp $

BUILDLINK_TREE+=	openjpeg

.if !defined(OPENJPEG_BUILDLINK3_MK)
OPENJPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjpeg+=	openjpeg>=1.3
BUILDLINK_ABI_DEPENDS.openjpeg+=	openjpeg>=1.5
BUILDLINK_PKGSRCDIR.openjpeg?=	../../graphics/openjpeg
.endif	# OPENJPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjpeg
