# $NetBSD: buildlink3.mk,v 1.14 2006/07/31 09:11:46 adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LOUDMOUTH_BUILDLINK3_MK:=	${LOUDMOUTH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	loudmouth
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nloudmouth}
BUILDLINK_PACKAGES+=	loudmouth
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}loudmouth

.if !empty(LOUDMOUTH_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.loudmouth+=	loudmouth>=1.0
BUILDLINK_ABI_DEPENDS.loudmouth+=	loudmouth>=1.0.1nb2
BUILDLINK_PKGSRCDIR.loudmouth?=	../../chat/loudmouth
.endif	# LOUDMOUTH_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
