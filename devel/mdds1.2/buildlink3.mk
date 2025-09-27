# $NetBSD: buildlink3.mk,v 1.2 2025/09/27 09:57:14 wiz Exp $

BUILDLINK_TREE+=	mdds1.2

.if !defined(MDDS12_BUILDLINK3_MK)
MDDS12_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdds1.2+=	mdds1.2>=1.2.0
BUILDLINK_ABI_DEPENDS.mdds1.2?=	mdds1.2>=1.3.1nb17
BUILDLINK_PKGSRCDIR.mdds1.2?=	../../devel/mdds1.2

# only contains header files
BUILDLINK_DEPMETHOD.mdds1.2?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# MDDS12_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds1.2
