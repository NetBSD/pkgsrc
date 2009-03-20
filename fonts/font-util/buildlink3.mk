# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:34 joerg Exp $

BUILDLINK_DEPMETHOD.font-util?=	build

BUILDLINK_TREE+=	font-util

.if !defined(FONT_UTIL_BUILDLINK3_MK)
FONT_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.font-util+=	font-util>=1.0.1
BUILDLINK_PKGSRCDIR.font-util?=	../../fonts/font-util
.endif # FONT_UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-font-util
