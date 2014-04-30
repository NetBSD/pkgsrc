# $NetBSD: buildlink3.mk,v 1.1 2014/04/30 16:25:20 marino Exp $

BUILDLINK_TREE+= gnat_util

.if !defined(GNAT_UTIL_BUILDLINK3_MK)
GNAT_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnat_util+=	gnat_util>=20140422
BUILDLINK_PKGSRCDIR.gnat_util?=	../../lang/gnat_util

.endif

BUILDLINK_TREE+= -gnat_util
