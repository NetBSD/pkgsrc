# $NetBSD: buildlink3.mk,v 1.1 2012/12/08 22:43:10 adam Exp $

BUILDLINK_TREE+=	openjpeg15

.if !defined(OPENJPEG15_BUILDLINK3_MK)
OPENJPEG15_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjpeg15+=	openjpeg15>=1.5.1
BUILDLINK_PKGSRCDIR.openjpeg15?=	../../graphics/openjpeg15
.endif	# OPENJPEG15_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjpeg15
