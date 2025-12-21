# $NetBSD: buildlink3.mk,v 1.1 2025/12/21 09:07:20 markd Exp $

BUILDLINK_TREE+=	opentimelineio

.if !defined(OPENTIMELINEIO_BUILDLINK3_MK)
OPENTIMELINEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opentimelineio+=	opentimelineio>=0.18.1
BUILDLINK_PKGSRCDIR.opentimelineio?=	../../multimedia/opentimelineio

.include "../../math/imath/buildlink3.mk"
.endif	# OPENTIMELINEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-opentimelineio
