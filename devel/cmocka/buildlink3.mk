# $NetBSD: buildlink3.mk,v 1.3 2026/06/11 07:21:24 wiz Exp $

BUILDLINK_TREE+=	cmocka

.if !defined(CMOCKA_BUILDLINK3_MK)
CMOCKA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmocka+=	cmocka>=1.1.3
BUILDLINK_ABI_DEPENDS.cmocka?=	cmocka>=2.0.2
BUILDLINK_PKGSRCDIR.cmocka?=	../../devel/cmocka
.endif	# CMOCKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmocka
