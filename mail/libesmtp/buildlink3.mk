# $NetBSD: buildlink3.mk,v 1.21 2023/10/24 22:09:45 wiz Exp $

BUILDLINK_TREE+=	libesmtp

.if !defined(LIBESMTP_BUILDLINK3_MK)
LIBESMTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libesmtp+=	libesmtp>=1.0rc1nb1
BUILDLINK_ABI_DEPENDS.libesmtp+=	libesmtp>=1.0.6nb6
BUILDLINK_PKGSRCDIR.libesmtp?=		../../mail/libesmtp

LIBESMTP=	-lesmtp

CONFIGURE_ENV+=	LIBESMTP=${LIBESMTP:Q}
MAKE_ENV+=	LIBESMTP=${LIBESMTP:Q}

.include "../../security/openssl/buildlink3.mk"
.endif # LIBESMTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libesmtp
