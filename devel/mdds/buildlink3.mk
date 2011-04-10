# $NetBSD: buildlink3.mk,v 1.1 2011/04/10 11:07:43 wiz Exp $

BUILDLINK_TREE+=	mdds

.if !defined(MDDS_BUILDLINK3_MK)
MDDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdds+=	mdds>=0.5.2
BUILDLINK_PKGSRCDIR.mdds?=	../../devel/mdds
# only contains header files
BUILDLINK_DEPMETHOD.mdds?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# MDDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds
