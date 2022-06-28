# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:47 wiz Exp $

BUILDLINK_TREE+=	libkgapi

.if !defined(LIBKGAPI_BUILDLINK3_MK)
LIBKGAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgapi+=	libkgapi>=2.2.0
BUILDLINK_ABI_DEPENDS.libkgapi?=		libkgapi>=2.2.0nb33
BUILDLINK_PKGSRCDIR.libkgapi?=		../../devel/libkgapi

.endif	# LIBKGAPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgapi
