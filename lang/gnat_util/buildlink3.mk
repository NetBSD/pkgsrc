# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:19 rillig Exp $

BUILDLINK_TREE+=	gnat_util

.if !defined(GNAT_UTIL_BUILDLINK3_MK)
GNAT_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnat_util+=	gnat_util>=20140422
BUILDLINK_PKGSRCDIR.gnat_util?=		../../lang/gnat_util

.endif

BUILDLINK_TREE+=	-gnat_util
