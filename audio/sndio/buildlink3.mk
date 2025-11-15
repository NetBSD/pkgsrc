# $NetBSD: buildlink3.mk,v 1.1 2025/11/15 21:38:42 vins Exp $

BUILDLINK_TREE+=	sndio

.if !defined(SNDIO_BUILDLINK3_MK)
SNDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sndio+=	sndio>=1.10.0
BUILDLINK_PKGSRCDIR.sndio?=	../../audio/sndio
.endif	# SNDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-sndio
