# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 10:22:03 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBKSBA_BUILDLINK3_MK:=	${LIBKSBA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libksba
.endif

.if !empty(LIBKSBA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libksba
BUILDLINK_DEPENDS.libksba+=	libksba>=0.9.1nb1
BUILDLINK_PKGSRCDIR.libksba?=	../../security/libksba

.  include "../../security/libgcrypt/buildlink3.mk"
.  include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBKSBA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
