# $NetBSD: buildlink3.mk,v 1.41 2020/05/31 19:13:11 bsiegert Exp $

BUILDLINK_TREE+=	devhelp

.if !defined(DEVHELP_BUILDLINK3_MK)
DEVHELP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.devhelp+=	devhelp>=3.34.0nb3
BUILDLINK_PKGSRCDIR.devhelp?=	../../devel/devhelp

.endif	# DEVHELP_BUILDLINK3_MK

BUILDLINK_TREE+=	-devhelp
