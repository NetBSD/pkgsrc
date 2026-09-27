# $NetBSD: buildlink3.mk,v 1.3 2026/09/27 11:38:25 tnn Exp $

BUILDLINK_TREE+=	liboauth2

.if !defined(LIBOAUTH2_BUILDLINK3_MK)
LIBOAUTH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboauth2+=	liboauth2>=2.3.0
BUILDLINK_ABI_DEPENDS.liboauth2?=		liboauth2>=2.3.0nb2
BUILDLINK_PKGSRCDIR.liboauth2?=		../../security/liboauth2

.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/cjose/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBOAUTH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboauth2
