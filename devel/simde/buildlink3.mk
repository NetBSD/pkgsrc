# $NetBSD: buildlink3.mk,v 1.1 2022/03/28 19:46:09 bacon Exp $

BUILDLINK_TREE+=	simde

.if !defined(SIMDE_BUILDLINK3_MK)
SIMDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simde+=	simde>=0.7.2
BUILDLINK_PKGSRCDIR.simde?=	../../devel/simde
BUILDLINK_DEPMETHOD.simde?=	build
.endif	# SIMDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-simde
