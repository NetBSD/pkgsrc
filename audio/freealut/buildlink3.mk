# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	freealut

.if !defined(FREEALUT_BUILDLINK3_MK)
FREEALUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freealut+=	freealut>=1.1.0
BUILDLINK_PKGSRCDIR.freealut?=	../../audio/freealut

.include "../../audio/openal/buildlink3.mk"
.endif # FREEALUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-freealut
