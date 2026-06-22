# $NetBSD: buildlink3.mk,v 1.8 2026/06/22 19:38:47 wiz Exp $

BUILDLINK_TREE+=	re2

.if !defined(RE2_BUILDLINK3_MK)
RE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.re2+=	re2>=20160201
BUILDLINK_ABI_DEPENDS.re2+=	re2>=20251105nb2
BUILDLINK_PKGSRCDIR.re2?=	../../devel/re2

.include "../../devel/abseil/buildlink3.mk"
.endif	# RE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-re2
