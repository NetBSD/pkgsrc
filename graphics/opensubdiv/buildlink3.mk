# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 15:21:57 ryoon Exp $

BUILDLINK_TREE+=	opensubdiv

.if !defined(OPENSUBDIV_BUILDLINK3_MK)
OPENSUBDIV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensubdiv+=	opensubdiv>=3.7_0
BUILDLINK_PKGSRCDIR.opensubdiv?=	../../graphics/opensubdiv

.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.endif	# OPENSUBDIV_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensubdiv
