# $NetBSD: buildlink3.mk,v 1.17 2012/03/03 00:12:28 wiz Exp $

BUILDLINK_TREE+=	wv2

.if !defined(WV2_BUILDLINK3_MK)
WV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wv2?=		wv2>=0.2.2nb1
BUILDLINK_ABI_DEPENDS.wv2?=	wv2>=0.2.3nb8
BUILDLINK_PKGSRCDIR.wv2?=	../../converters/wv2

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.endif # WV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-wv2
