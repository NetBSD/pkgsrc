# $NetBSD: buildlink3.mk,v 1.1 2020/03/20 11:05:03 wiz Exp $

BUILDLINK_TREE+=	wcslib

.if !defined(WCSLIB_BUILDLINK3_MK)
WCSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wcslib+=	wcslib>=7.2
BUILDLINK_PKGSRCDIR.wcslib?=	../../graphics/wcslib
.endif # WCSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-wcslib
