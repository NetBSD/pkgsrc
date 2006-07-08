# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 22:39:25 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMAP_UW_BUILDLINK3_MK:=	${IMAP_UW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	imap-uw
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nimap-uw}
BUILDLINK_PACKAGES+=	imap-uw
BUILDLINK_ORDER+=	imap-uw

.if !empty(IMAP_UW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.imap-uw+=	imap-uw>=2004
BUILDLINK_ABI_DEPENDS.imap-uw+=	imap-uw>=2004enb1
BUILDLINK_PKGSRCDIR.imap-uw?=	../../mail/imap-uw
#
# Make "-limapuw" resolve into "-lc-client".
#
BUILDLINK_TRANSFORM+=		l:imapuw:c-client

.endif	# IMAP_UW_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
