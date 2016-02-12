# $NetBSD: buildlink3.mk,v 1.1 2016/02/12 13:34:45 wiz Exp $

BUILDLINK_TREE+=	mdds012

.if !defined(MDDS012_BUILDLINK3_MK)
MDDS012_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdds012+=	mdds0.12>=0.9.0nb1
BUILDLINK_PKGSRCDIR.mdds012?=	../../devel/mdds0.12
# only contains header files
BUILDLINK_DEPMETHOD.mdds012?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# MDDS012_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds012
