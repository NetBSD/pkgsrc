# $NetBSD: buildlink3.mk,v 1.2 2022/05/15 12:09:49 tnn Exp $

BUILDLINK_TREE+=	faudio

.if !defined(FAUDIO_BUILDLINK3_MK)
FAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faudio+=	faudio>=22.05
BUILDLINK_PKGSRCDIR.faudio?=	../../audio/faudio
.endif	# FAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-faudio
