# $NetBSD: buildlink3.mk,v 1.4 2004/03/18 09:12:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LOUDMOUTH_BUILDLINK3_MK:=	${LOUDMOUTH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	loudmouth
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nloudmouth}
BUILDLINK_PACKAGES+=	loudmouth

.if !empty(LOUDMOUTH_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.loudmouth+=	loudmouth>=0.15.1nb3
BUILDLINK_PKGSRCDIR.loudmouth?=	../../chat/loudmouth
.endif	# LOUDMOUTH_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
