# $NetBSD: buildlink3.mk,v 1.3 2014/09/08 16:02:35 wiz Exp $

BUILDLINK_TREE+=	netatalk

.if !defined(NETATALK_BUILDLINK3_MK)
NETATALK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netatalk+=	netatalk22>=2.0.3nb2
BUILDLINK_ABI_DEPENDS.netatalk+=	netatalk22>=2.0.3nb3
BUILDLINK_PKGSRCDIR.netatalk?=	../../net/netatalk22
BUILDLINK_DEPMETHOD.netatalk?=	build
.endif # NETATALK_BUILDLINK3_MK

BUILDLINK_TREE+=	-netatalk
