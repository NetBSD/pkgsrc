# $NetBSD: buildlink3.mk,v 1.14 2024/05/19 12:54:59 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.2.6.4
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc

.include "../../devel/libxtend/buildlink3.mk"
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
