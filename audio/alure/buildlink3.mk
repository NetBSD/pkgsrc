# $NetBSD: buildlink3.mk,v 1.1 2018/09/21 13:24:34 maya Exp $

BUILDLINK_TREE+=	alure

.if !defined(ALURE_BUILDLINK3_MK)
ALURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alure+=	alure>=1.2
BUILDLINK_PKGSRCDIR.alure?=	../../audio/alure

.include "../../audio/openal-soft/buildlink3.mk"
.endif	# ALURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-alure
