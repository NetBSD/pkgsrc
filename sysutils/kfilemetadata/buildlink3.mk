# $NetBSD: buildlink3.mk,v 1.2 2014/11/15 20:48:10 markd Exp $

BUILDLINK_TREE+=	kfilemetadata

.if !defined(KFILEMETADATA_BUILDLINK3_MK)
KFILEMETADATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kfilemetadata+=	kfilemetadata>=4.14.3
BUILDLINK_PKGSRCDIR.kfilemetadata?=	../../sysutils/kfilemetadata

.endif	# KFILEMETADATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kfilemetadata
