# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:23:58 joerg Exp $

BUILDLINK_TREE+=	openal

.if !defined(OPENAL_BUILDLINK3_MK)
OPENAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openal+=	openal>=0.0.8
BUILDLINK_PKGSRCDIR.openal?=	../../audio/openal
.endif # OPENAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openal
