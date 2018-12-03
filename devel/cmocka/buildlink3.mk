# $NetBSD: buildlink3.mk,v 1.1 2018/12/03 15:16:33 adam Exp $

BUILDLINK_TREE+=	cmocka

.if !defined(CMOCKA_BUILDLINK3_MK)
CMOCKA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmocka+=	cmocka>=1.1.3
BUILDLINK_PKGSRCDIR.cmocka?=	../../devel/cmocka
.endif	# CMOCKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmocka
