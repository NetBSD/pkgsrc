# $NetBSD: buildlink3.mk,v 1.1 2004/04/22 21:31:22 ben Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMAP_UW_BUILDLINK3_MK:=	${IMAP_UW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	imap-uw
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nimap-uw}
BUILDLINK_PACKAGES+=	imap-uw

.if !empty(IMAP_UW_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.imap-uw+=	imap-uw>=2002.5nb3
BUILDLINK_PKGSRCDIR.imap-uw?=	../../mail/imap-uw
.endif	# IMAP_UW_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
