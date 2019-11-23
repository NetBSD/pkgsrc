# $NetBSD: buildlink3.mk,v 1.2 2019/11/23 08:45:45 mef Exp $

BUILDLINK_TREE+=	cmocka

.if !defined(CMOCKA_BUILDLINK3_MK)
CMOCKA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmocka+=	cmocka>=1.1.3
BUILDLINK_ABI_DEPENDS.cmocka?=	cmocka>=1.1.5
BUILDLINK_PKGSRCDIR.cmocka?=	../../devel/cmocka
.endif	# CMOCKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmocka
