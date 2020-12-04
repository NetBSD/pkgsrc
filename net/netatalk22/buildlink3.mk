# $NetBSD: buildlink3.mk,v 1.5 2020/12/04 04:56:08 riastradh Exp $

BUILDLINK_TREE+=	netatalk

.if !defined(NETATALK_BUILDLINK3_MK)
NETATALK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netatalk+=	netatalk22>=2.0.3nb2
BUILDLINK_ABI_DEPENDS.netatalk+=	netatalk22>=2.2.6nb22
BUILDLINK_PKGSRCDIR.netatalk?=		../../net/netatalk22
BUILDLINK_DEPMETHOD.netatalk?=		build
.endif # NETATALK_BUILDLINK3_MK

BUILDLINK_TREE+=	-netatalk
