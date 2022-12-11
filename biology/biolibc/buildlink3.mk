# $NetBSD: buildlink3.mk,v 1.10 2022/12/11 21:14:37 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.2.4
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc

.include "../../devel/libxtend/buildlink3.mk"
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
