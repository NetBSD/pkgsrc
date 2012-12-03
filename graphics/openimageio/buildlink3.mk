# $NetBSD: buildlink3.mk,v 1.1 2012/12/03 12:54:14 ryoon Exp $

BUILDLINK_TREE+=	openimageio

.if !defined(OPENIMAGEIO_BUILDLINK3_MK)
OPENIMAGEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openimageio+=	openimageio>=1.1.1
BUILDLINK_PKGSRCDIR.openimageio?=	../../graphics/openimageio

.endif	# OPENIMAGEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-openimageio
