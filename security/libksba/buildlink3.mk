# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:39 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBKSBA_BUILDLINK3_MK:=	${LIBKSBA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libksba
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibksba}
BUILDLINK_PACKAGES+=	libksba

.if !empty(LIBKSBA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libksba+=	libksba>=0.9.4
BUILDLINK_PKGSRCDIR.libksba?=	../../security/libksba

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"

.endif	# LIBKSBA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
