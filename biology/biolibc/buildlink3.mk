# $NetBSD: buildlink3.mk,v 1.1 2021/03/24 15:20:08 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.1.1
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc
BUILDLINK_DEPMETHOD.biolibc?=	build
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
