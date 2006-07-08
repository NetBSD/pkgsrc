# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:07 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGPG_ERROR_BUILDLINK3_MK:=	${LIBGPG_ERROR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgpg-error
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgpg-error}
BUILDLINK_PACKAGES+=	libgpg-error
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgpg-error

.if !empty(LIBGPG_ERROR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=0.6
BUILDLINK_ABI_DEPENDS.libgpg-error+=	libgpg-error>=1.0nb1
BUILDLINK_PKGSRCDIR.libgpg-error?=	../../security/libgpg-error
.endif	# LIBGPG_ERROR_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
