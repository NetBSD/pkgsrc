# $NetBSD: buildlink3.mk,v 1.2 2026/02/14 18:31:50 adam Exp $

BUILDLINK_TREE+=	wcslib

.if !defined(WCSLIB_BUILDLINK3_MK)
WCSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wcslib+=	wcslib>=7.2
BUILDLINK_PKGSRCDIR.wcslib?=	../../graphics/wcslib

BUILDLINK_TARGETS+=	buildlink-include-wcslib

.PHONY: buildlink-include-wcslib
buildlink-include-wcslib:
	${LN} -s ${BUILDLINK_DIR}/include/wcslib-8.5 ${BUILDLINK_DIR}/include/wcslib

.endif # WCSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-wcslib
