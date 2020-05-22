# $NetBSD: buildlink3.mk,v 1.1 2020/05/22 09:04:29 nia Exp $

BUILDLINK_TREE+=	faudio

.if !defined(FAUDIO_BUILDLINK3_MK)
FAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faudio+=	faudio>=20.05
BUILDLINK_PKGSRCDIR.faudio?=	../../audio/faudio
.endif	# FAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-faudio
