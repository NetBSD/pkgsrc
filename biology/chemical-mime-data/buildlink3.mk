# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/05 22:10:56 ryoon Exp $

BUILDLINK_TREE+=	chemical-mime-data

.if !defined(CHEMICAL_MIME_DATA_BUILDLINK3_MK)
CHEMICAL_MIME_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chemical-mime-data+=	chemical-mime-data>=0.1.94nb1
BUILDLINK_PKGSRCDIR.chemical-mime-data?=	../../biology/chemical-mime-data

.endif	# CHEMICAL_MIME_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-chemical-mime-data
