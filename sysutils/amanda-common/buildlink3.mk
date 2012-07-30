# $NetBSD: buildlink3.mk,v 1.13 2012/07/30 06:57:21 sbd Exp $

BUILDLINK_TREE+=	amanda-common

.if !defined(AMANDA_COMMON_BUILDLINK3_MK)
AMANDA_COMMON_BUILDLINK3_MK:=
.include "version.mk"

BUILDLINK_API_DEPENDS.amanda-common+=	amanda-common>=${AMANDA_VERSION}
BUILDLINK_ABI_DEPENDS.amanda-common+=	amanda-common>=${AMANDA_VERSION}
BUILDLINK_PKGSRCDIR.amanda-common?=	../../sysutils/amanda-common
.endif # AMANDA_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-amanda-common
