# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:12 rillig Exp $

BUILDLINK_TREE+=	font-util

.if !defined(FONT_UTIL_BUILDLINK3_MK)
FONT_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.font-util+=	font-util>=1.0.1
BUILDLINK_PKGSRCDIR.font-util?=		../../fonts/font-util

BUILDLINK_DEPMETHOD.font-util?=	build
.endif # FONT_UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-font-util
