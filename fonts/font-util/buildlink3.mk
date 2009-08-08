# $NetBSD: buildlink3.mk,v 1.3 2009/08/08 23:18:58 wiz Exp $

BUILDLINK_TREE+=	font-util

.if !defined(FONT_UTIL_BUILDLINK3_MK)
FONT_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.font-util+=	font-util>=1.0.1
BUILDLINK_PKGSRCDIR.font-util?=	../../fonts/font-util

BUILDLINK_DEPMETHOD.font-util?=	build
.endif # FONT_UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-font-util
