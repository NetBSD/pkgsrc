# $NetBSD: buildlink3.mk,v 1.2 2020/09/05 11:34:07 ryoon Exp $

BUILDLINK_TREE+=	threadingbuildingblocks

.if !defined(THREADINGBUILDINGBLOCKS_BUILDLINK3_MK)
THREADINGBUILDINGBLOCKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.threadingbuildingblocks+=	threadingbuildingblocks>=2020.3
BUILDLINK_PKGSRCDIR.threadingbuildingblocks?=	../../parallel/threadingbuildingblocks
.endif	# THREADINGBUILDINGBLOCKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-threadingbuildingblocks
