# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 00:13:24 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGCRYPT_BUILDLINK3_MK:=	${LIBGCRYPT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgcrypt
.endif

.if !empty(LIBGCRYPT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libgcrypt
BUILDLINK_DEPENDS.libgcrypt+=	libgcrypt>=1.1.90
BUILDLINK_PKGSRCDIR.libgcrypt?=	../../security/libgcrypt

.  include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBGCRYPT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
