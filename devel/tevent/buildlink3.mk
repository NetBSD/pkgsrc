# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:17 wiz Exp $

BUILDLINK_TREE+=	tevent

.if !defined(TEVENT_BUILDLINK3_MK)
TEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tevent+=	tevent>=0.9.37
BUILDLINK_ABI_DEPENDS.tevent?=	tevent>=0.14.1nb1
BUILDLINK_PKGSRCDIR.tevent?=	../../devel/tevent

.include "../../devel/talloc/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"

.endif	# TEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tevent
