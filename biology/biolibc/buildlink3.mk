# $NetBSD: buildlink3.mk,v 1.13 2023/10/28 20:31:40 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.2.6
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc

.include "../../devel/libxtend/buildlink3.mk"
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
