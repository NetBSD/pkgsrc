# $NetBSD: buildlink3.mk,v 1.15 2016/03/05 11:27:46 jperkin Exp $
#
# This Makefile fragment is included by packages that use rudiments.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_TREE+=	rudiments

.if !defined(RUDIMENTS_BUILDLINK3_MK)
RUDIMENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rudiments+=	rudiments>=0.54
BUILDLINK_ABI_DEPENDS.rudiments?=		rudiments>=0.54nb2
BUILDLINK_PKGSRCDIR.rudiments?=		../../devel/rudiments

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # RUDIMENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rudiments
