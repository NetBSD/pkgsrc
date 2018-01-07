# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:32 rillig Exp $

BUILDLINK_TREE+=	libbaloo4

.if !defined(LIBBALOO4_BUILDLINK3_MK)
LIBBALOO4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbaloo4+=	libbaloo4>=4.14.3
BUILDLINK_PKGSRCDIR.libbaloo4?=		../../sysutils/libbaloo4

.include "../../sysutils/kfilemetadata/buildlink3.mk"
.endif	# LIBBALOO4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbaloo4
