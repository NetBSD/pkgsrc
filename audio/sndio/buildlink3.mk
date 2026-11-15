# $NetBSD: buildlink3.mk,v 1.2 2026/11/15 16:06:08 vins Exp $

BUILDLINK_TREE+=	sndio

.if !defined(SNDIO_BUILDLINK3_MK)
SNDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sndio+=	sndio>=1.11.0
BUILDLINK_PKGSRCDIR.sndio?=	../../audio/sndio
.endif	# SNDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-sndio
