# $NetBSD: buildlink3.mk,v 1.1 2014/11/13 11:13:45 markd Exp $

BUILDLINK_TREE+=	libkgapi

.if !defined(LIBKGAPI_BUILDLINK3_MK)
LIBKGAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgapi+=	libkgapi>=2.2.0
BUILDLINK_PKGSRCDIR.libkgapi?=	../../devel/libkgapi

.endif	# LIBKGAPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgapi
