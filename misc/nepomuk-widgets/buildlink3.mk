# $NetBSD: buildlink3.mk,v 1.1 2013/04/03 10:51:47 markd Exp $

BUILDLINK_TREE+=	nepomuk-widgets

.if !defined(NEPOMUK_WIDGETS_BUILDLINK3_MK)
NEPOMUK_WIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nepomuk-widgets+=	nepomuk-widgets>=4.10.1
BUILDLINK_PKGSRCDIR.nepomuk-widgets?=	../../misc/nepomuk-widgets

.endif	# NEPOMUK_WIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nepomuk-widgets
