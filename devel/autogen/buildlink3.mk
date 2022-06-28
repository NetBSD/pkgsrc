# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:39 wiz Exp $

BUILDLINK_TREE+=	autogen

.if !defined(AUTOGEN_BUILDLINK3_MK)
AUTOGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.autogen+=	autogen>=5.12nb5
BUILDLINK_ABI_DEPENDS.autogen?=	autogen>=5.18.16nb7
BUILDLINK_PKGSRCDIR.autogen?=	../../devel/autogen

.endif	# AUTOGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-autogen
