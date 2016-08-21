# $NetBSD: buildlink3.mk,v 1.1 2016/08/21 21:09:27 markd Exp $

BUILDLINK_TREE+=	attr

.if !defined(ATTR_BUILDLINK3_MK)
ATTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.attr+=	attr>=2.4.47nb1
BUILDLINK_PKGSRCDIR.attr?=	../../sysutils/attr

.endif	# ATTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-attr
