# $NetBSD: buildlink3.mk,v 1.2 2019/11/04 21:28:44 rillig Exp $

BUILDLINK_TREE+=	e2fsprogs

.if !defined(E2FSPROGS_BUILDLINK3_MK)
E2FSPROGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.e2fsprogs+=	e2fsprogs>=1.43.7nb1
BUILDLINK_PKGSRCDIR.e2fsprogs?=		../../sysutils/e2fsprogs

.endif	# E2FSPROGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-e2fsprogs
