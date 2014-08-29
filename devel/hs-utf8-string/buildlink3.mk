# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:08:40 szptvlfn Exp $

BUILDLINK_TREE+=	hs-utf8-string

.if !defined(HS_UTF8_STRING_BUILDLINK3_MK)
HS_UTF8_STRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-utf8-string+=	hs-utf8-string>=0.3.8
BUILDLINK_ABI_DEPENDS.hs-utf8-string+=	hs-utf8-string>=0.3.8
BUILDLINK_PKGSRCDIR.hs-utf8-string?=	../../devel/hs-utf8-string
.endif	# HS_UTF8_STRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-utf8-string
