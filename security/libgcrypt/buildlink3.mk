# $NetBSD: buildlink3.mk,v 1.8 2004/11/14 15:38:42 ben Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGCRYPT_BUILDLINK3_MK:=	${LIBGCRYPT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgcrypt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgcrypt}
BUILDLINK_PACKAGES+=	libgcrypt

.if !empty(LIBGCRYPT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgcrypt+=	libgcrypt>=1.2.0
BUILDLINK_RECOMMENDED.libgcrypt+=	libgcrypt>=1.2.0nb3
BUILDLINK_PKGSRCDIR.libgcrypt?=	../../security/libgcrypt
.endif	# LIBGCRYPT_BUILDLINK3_MK

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
