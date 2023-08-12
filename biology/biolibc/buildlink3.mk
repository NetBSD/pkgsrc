# $NetBSD: buildlink3.mk,v 1.12 2023/08/12 14:49:18 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.2.5
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc

.include "../../devel/libxtend/buildlink3.mk"
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
