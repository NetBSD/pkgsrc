# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:35:51 wiz Exp $

BUILDLINK_TREE+=	sleuthkit

.if !defined(SLEUTHKIT_BUILDLINK3_MK)
SLEUTHKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sleuthkit+=	sleuthkit>=4.1.3nb3
BUILDLINK_ABI_DEPENDS.sleuthkit?=		sleuthkit>=4.1.3nb10
BUILDLINK_PKGSRCDIR.sleuthkit?=		../../security/sleuthkit

.endif	# SLEUTHKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sleuthkit
