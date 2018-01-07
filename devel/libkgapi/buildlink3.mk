# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:06 rillig Exp $

BUILDLINK_TREE+=	libkgapi

.if !defined(LIBKGAPI_BUILDLINK3_MK)
LIBKGAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgapi+=	libkgapi>=2.2.0
BUILDLINK_PKGSRCDIR.libkgapi?=		../../devel/libkgapi

.endif	# LIBKGAPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgapi
