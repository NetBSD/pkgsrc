# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:56:56 markd Exp $

BUILDLINK_TREE+=	kf6-kfilemetadata

.if !defined(KF6_KFILEMETADATA_BUILDLINK3_MK)
KF6_KFILEMETADATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kfilemetadata+=	kf6-kfilemetadata>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kfilemetadata?=		../../sysutils/kf6-kfilemetadata

.endif	# KF6_KFILEMETADATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kfilemetadata
