# $NetBSD: buildlink3.mk,v 1.1 2018/04/28 09:40:39 wiz Exp $

BUILDLINK_TREE+=	woff2

.if !defined(WOFF2_BUILDLINK3_MK)
WOFF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.woff2+=	woff2>=1.0.2
BUILDLINK_PKGSRCDIR.woff2?=	../../fonts/woff2

.include "../../archivers/brotli/buildlink3.mk"
.endif	# WOFF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-woff2
