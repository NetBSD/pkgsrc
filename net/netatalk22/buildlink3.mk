# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:27 rillig Exp $

BUILDLINK_TREE+=	netatalk

.if !defined(NETATALK_BUILDLINK3_MK)
NETATALK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netatalk+=	netatalk22>=2.0.3nb2
BUILDLINK_ABI_DEPENDS.netatalk+=	netatalk22>=2.0.3nb3
BUILDLINK_PKGSRCDIR.netatalk?=		../../net/netatalk22
BUILDLINK_DEPMETHOD.netatalk?=		build
.endif # NETATALK_BUILDLINK3_MK

BUILDLINK_TREE+=	-netatalk
