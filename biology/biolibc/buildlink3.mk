# $NetBSD: buildlink3.mk,v 1.6 2021/09/18 00:42:39 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.2.0
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
