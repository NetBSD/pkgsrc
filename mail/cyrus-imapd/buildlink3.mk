# $NetBSD: buildlink3.mk,v 1.1 2004/04/25 01:13:25 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CYRUS_IMAPD_BUILDLINK3_MK:=	${CYRUS_IMAPD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cyrus-imapd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncyrus-imapd}
BUILDLINK_PACKAGES+=	cyrus-imapd

.if !empty(CYRUS_IMAPD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.cyrus-imapd+=	cyrus-imapd>=2.0.17nb3
BUILDLINK_PKGSRCDIR.cyrus-imapd?=	../../mail/cyrus-imapd
.endif	# CYRUS_IMAPD_BUILDLINK3_MK

.include "../../databases/db3/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
