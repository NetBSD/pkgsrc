# $NetBSD: buildlink3.mk,v 1.6 2023/10/13 06:18:01 wiz Exp $

BUILDLINK_TREE+=	libimagequant

.if !defined(LIBIMAGEQUANT_BUILDLINK3_MK)
LIBIMAGEQUANT_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

.include "../../graphics/libimagequant/available.mk"

.if ${LIBIMAGEQUANT_TYPE:tl} == "rust"
BUILDLINK_API_DEPENDS.libimagequant+=	libimagequant>=4.2.0
BUILDLINK_PKGSRCDIR.libimagequant?=	../../graphics/libimagequant
.elif ${LIBIMAGEQUANT_TYPE:tl} == "c"
BUILDLINK_API_DEPENDS.libimagequant+=	libimagequant>=2.17.0<3.0.0
BUILDLINK_PKGSRCDIR.libimagequant?=	../../graphics/libimagequant-c
.else
PKG_FAIL_REASON+=			"[graphics/libimagequant/buildlink3.mk] Invalid value ${LIBIMAGEQUANT_TYPE} for LIBIMAGEQUANT_TYPE."
.endif

.endif	# LIBIMAGEQUANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimagequant
