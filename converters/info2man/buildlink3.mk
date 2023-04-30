# $NetBSD: buildlink3.mk,v 1.1 2023/04/30 14:07:04 nikita Exp $

BUILDLINK_TREE+=	info2man

.if !defined(INFO2MAN_BUILDLINK3_MK)
INFO2MAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.info2man+=	info2man>=1.1
BUILDLINK_PKGSRCDIR.info2man?=		../../converters/info2man
.endif	# INFO2MAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-info2man
