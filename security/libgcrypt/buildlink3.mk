# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:39 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGCRYPT_BUILDLINK3_MK:=	${LIBGCRYPT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgcrypt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgcrypt}
BUILDLINK_PACKAGES+=	libgcrypt

.if !empty(LIBGCRYPT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgcrypt+=	libgcrypt>=1.1.92
BUILDLINK_PKGSRCDIR.libgcrypt?=	../../security/libgcrypt

.include "../../security/libgpg-error/buildlink3.mk"

.endif	# LIBGCRYPT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
