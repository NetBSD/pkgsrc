# $NetBSD: buildlink3.mk,v 1.2 2004/02/09 23:56:33 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGPG_ERROR_BUILDLINK3_MK:=	${LIBGPG_ERROR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgpg-error
.endif

.if !empty(LIBGPG_ERROR_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgpg-error
BUILDLINK_DEPENDS.libgpg-error+=	libgpg-error>=0.6
BUILDLINK_PKGSRCDIR.libgpg-error?=	../../security/libgpg-error

.  include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBGPG_ERROR_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
