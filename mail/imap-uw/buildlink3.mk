# $NetBSD: buildlink3.mk,v 1.14 2008/04/20 22:41:57 dbj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMAP_UW_BUILDLINK3_MK:=	${IMAP_UW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	imap-uw
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nimap-uw}
BUILDLINK_PACKAGES+=	imap-uw
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}imap-uw

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(IMAP_UW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.imap-uw+=	imap-uw>=2004
BUILDLINK_ABI_DEPENDS.imap-uw+=	imap-uw>=2006j2nb5
BUILDLINK_PKGSRCDIR.imap-uw?=	../../mail/imap-uw
. if ${OPSYS} == "Darwin"
BUILDLINK_LDFLAGS.imap-uw+=	-flat_namespace
# install will strip the c-client library callback
# function symbols from the executable unless we do this:
INSTALL_UNSTRIPPED?=	yes
. endif
.endif	# IMAP_UW_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
