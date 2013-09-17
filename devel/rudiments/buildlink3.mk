# $NetBSD: buildlink3.mk,v 1.9 2013/09/17 11:58:57 fhajny Exp $
#
# This Makefile fragment is included by packages that use rudiments.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_TREE+=	rudiments

.if !defined(RUDIMENTS_BUILDLINK3_MK)
RUDIMENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rudiments+=		rudiments>=0.25.1
BUILDLINK_ABI_DEPENDS.rudiments+=	rudiments>=0.28.2nb1
BUILDLINK_PKGSRCDIR.rudiments?=		../../devel/rudiments

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # RUDIMENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rudiments
