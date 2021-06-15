# $NetBSD: buildlink3.mk,v 1.3 2021/06/15 13:47:46 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.1.3
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
