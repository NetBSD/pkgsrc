# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:03:54 rillig Exp $

BUILDLINK_TREE+=	freealut

.if !defined(FREEALUT_BUILDLINK3_MK)
FREEALUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freealut+=	freealut>=1.1.0
BUILDLINK_PKGSRCDIR.freealut?=		../../audio/freealut

.include "../../audio/openal-soft/buildlink3.mk"
.endif # FREEALUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-freealut
