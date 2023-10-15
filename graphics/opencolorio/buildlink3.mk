# $NetBSD: buildlink3.mk,v 1.3 2023/10/15 19:45:33 ryoon Exp $

BUILDLINK_TREE+=	opencolorio

.if !defined(OPENCOLORIO_BUILDLINK3_MK)
OPENCOLORIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencolorio+=	opencolorio>=2.2.1
BUILDLINK_PKGSRCDIR.opencolorio?=	../../graphics/opencolorio

.endif	# OPENCOLORIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencolorio
