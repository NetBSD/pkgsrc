# $NetBSD: buildlink3.mk,v 1.44 2024/05/16 06:14:48 wiz Exp $

BUILDLINK_TREE+=	rudiments

.if !defined(RUDIMENTS_BUILDLINK3_MK)
RUDIMENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rudiments+=	rudiments>=1.1.0
BUILDLINK_ABI_DEPENDS.rudiments+=	rudiments>=1.4.2nb4
BUILDLINK_PKGSRCDIR.rudiments?=		../../devel/rudiments

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # RUDIMENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rudiments
