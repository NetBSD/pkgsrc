# $NetBSD: buildlink3.mk,v 1.1 2024/09/02 16:04:24 nia Exp $

BUILDLINK_TREE+=	rnnoise

.if !defined(RNNOISE_BUILDLINK3_MK)
RNNOISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rnnoise+=	rnnoise>=0.2
BUILDLINK_PKGSRCDIR.rnnoise?=	../../audio/rnnoise
.endif	# RNNOISE_BUILDLINK3_MK

BUILDLINK_TREE+=	-rnnoise
