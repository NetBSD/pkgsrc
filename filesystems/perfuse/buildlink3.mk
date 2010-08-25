# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/25 07:34:11 manu Exp $

BUILDLINK_TREE+=	perfuse

.if !defined(PERFUSE_BUILDLINK3_MK)
PERFUSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.perfuse+=	perfuse>=10100822
BUILDLINK_PKGSRCDIR.perfuse?=	../../filesystems/perfuse
.endif # PERFUSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-perfuse
