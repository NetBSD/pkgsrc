# $NetBSD: buildlink3.mk,v 1.8 2022/03/15 21:06:32 bacon Exp $

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.2.2
BUILDLINK_PKGSRCDIR.biolibc?=	../../biology/biolibc

.include "../../devel/libxtend/buildlink3.mk"
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
