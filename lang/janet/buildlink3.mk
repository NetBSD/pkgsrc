# $NetBSD: buildlink3.mk,v 1.1 2020/03/03 09:44:02 nia Exp $

BUILDLINK_TREE+=	janet

.if !defined(JANET_BUILDLINK3_MK)
JANET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.janet+=	janet>=1.7.0
BUILDLINK_PKGSRCDIR.janet?=	../../lang/janet
.endif	# JANET_BUILDLINK3_MK

BUILDLINK_TREE+=	-janet
