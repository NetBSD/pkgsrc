# $NetBSD: buildlink3.mk,v 1.1 2024/11/05 17:08:40 adam Exp $
# XXX unverified buildlink3.mk files.

BUILDLINK_TREE+=	zix

.if !defined(ZIX_BUILDLINK3_MK)
ZIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zix+=	zix>=0.4.2
BUILDLINK_PKGSRCDIR.zix?=	../../devel/zix

.endif	# ZIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-zix
