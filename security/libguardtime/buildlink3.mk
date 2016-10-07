# $NetBSD: buildlink3.mk,v 1.4 2016/10/07 18:25:33 adam Exp $

BUILDLINK_TREE+=	libguardtime

.if !defined(LIBGUARDTIME_BUILDLINK3_MK)
LIBGUARDTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libguardtime+=	libguardtime>=0.3.11
BUILDLINK_ABI_DEPENDS.libguardtime+=	libguardtime>=0.3.13nb2
BUILDLINK_PKGSRCDIR.libguardtime?=	../../security/libguardtime

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libguardtime
