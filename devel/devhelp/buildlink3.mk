# $NetBSD: buildlink3.mk,v 1.42 2023/08/14 05:24:06 wiz Exp $

BUILDLINK_TREE+=	devhelp

.if !defined(DEVHELP_BUILDLINK3_MK)
DEVHELP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.devhelp+=	devhelp>=3.34.0nb3
BUILDLINK_ABI_DEPENDS.devhelp?=	devhelp>=3.34.0nb17
BUILDLINK_PKGSRCDIR.devhelp?=	../../devel/devhelp

.endif	# DEVHELP_BUILDLINK3_MK

BUILDLINK_TREE+=	-devhelp
