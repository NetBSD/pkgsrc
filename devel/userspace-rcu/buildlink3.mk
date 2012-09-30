# $NetBSD: buildlink3.mk,v 1.1 2012/09/30 22:06:17 pettai Exp $

BUILDLINK_TREE+=	userspace-rcu

.if !defined(USERSPACE_RCU_BUILDLINK3_MK)
USERSPACE_RCU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.userspace-rcu+=	userspace-rcu>=0.7.3
BUILDLINK_PKGSRCDIR.userspace-rcu?=	../../devel/userspace-rcu
.endif	# USERSPACE_RCU_BUILDLINK3_MK

BUILDLINK_TREE+=	-userspace-rcu
