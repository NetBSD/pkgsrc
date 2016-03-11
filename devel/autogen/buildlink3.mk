# $NetBSD: buildlink3.mk,v 1.1 2016/03/11 11:48:59 wiz Exp $

BUILDLINK_TREE+=	autogen

.if !defined(AUTOGEN_BUILDLINK3_MK)
AUTOGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.autogen+=	autogen>=5.12nb5
BUILDLINK_PKGSRCDIR.autogen?=	../../devel/autogen

.endif	# AUTOGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-autogen
