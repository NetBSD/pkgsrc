# $NetBSD: buildlink3.mk,v 1.5 2004/10/03 00:18:09 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBKSBA_BUILDLINK3_MK:=	${LIBKSBA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libksba
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibksba}
BUILDLINK_PACKAGES+=	libksba

.if !empty(LIBKSBA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libksba+=	libksba>=0.9.4
BUILDLINK_RECOMMENDED.libksba+=	libksba>=0.9.4nb1
BUILDLINK_PKGSRCDIR.libksba?=	../../security/libksba
.endif	# LIBKSBA_BUILDLINK3_MK

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
