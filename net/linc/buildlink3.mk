# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:17:55 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LINC_BUILDLINK3_MK:=	${LINC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	linc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlinc}
BUILDLINK_PACKAGES+=	linc

.if !empty(LINC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.linc+=	linc>=1.1.1
BUILDLINK_RECOMMENDED.linc+=	linc>=1.1.1nb2
BUILDLINK_PKGSRCDIR.linc?=	../../net/linc
.endif	# LINC_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
