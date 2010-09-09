# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/09 02:15:22 joerg Exp $

BUILDLINK_TREE+=	openjpeg

.if !defined(OPENJPEG_BUILDLINK3_MK)
OPENJPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjpeg+=	openjpeg>=1.3
BUILDLINK_PKGSRCDIR.openjpeg?=	../../graphics/openjpeg
.endif	# OPENJPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjpeg
