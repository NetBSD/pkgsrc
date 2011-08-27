# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/08/27 19:48:13 asau Exp $

BUILDLINK_TREE+=	threadingbuildingblocks

.if !defined(THREADINGBUILDINGBLOCKS_BUILDLINK3_MK)
THREADINGBUILDINGBLOCKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.threadingbuildingblocks+=	threadingbuildingblocks>=3.0.6
BUILDLINK_PKGSRCDIR.threadingbuildingblocks?=	../../parallel/threadingbuildingblocks
.endif	# THREADINGBUILDINGBLOCKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-threadingbuildingblocks
