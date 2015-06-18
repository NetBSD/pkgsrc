# $NetBSD: buildlink3.mk,v 1.1 2015/06/18 13:01:44 pettai Exp $

BUILDLINK_TREE+=	sleuthkit

.if !defined(SLEUTHKIT_BUILDLINK3_MK)
SLEUTHKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sleuthkit+=	sleuthkit>=4.1.3nb3
BUILDLINK_PKGSRCDIR.sleuthkit?=	../../security/sleuthkit

.endif	# SLEUTHKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sleuthkit
