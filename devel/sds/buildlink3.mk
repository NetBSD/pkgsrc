# $NetBSD: buildlink3.mk,v 1.1 2023/01/27 10:30:49 micha Exp $

BUILDLINK_TREE+=	sds

.if !defined(SDS_BUILDLINK3_MK)
SDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sds+=	sds>=2.2
BUILDLINK_PKGSRCDIR.sds?=	../../devel/sds
.endif	# SDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sds
