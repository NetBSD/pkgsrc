# $NetBSD: buildlink3.mk,v 1.38 2021/09/29 19:00:06 adam Exp $

BUILDLINK_TREE+=	rudiments

.if !defined(RUDIMENTS_BUILDLINK3_MK)
RUDIMENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rudiments+=	rudiments>=1.1.0
BUILDLINK_ABI_DEPENDS.rudiments+=	rudiments>=1.3.1nb2
BUILDLINK_PKGSRCDIR.rudiments?=		../../devel/rudiments

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # RUDIMENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rudiments
