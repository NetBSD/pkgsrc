# $NetBSD: buildlink3.mk,v 1.20 2015/09/07 12:02:06 jperkin Exp $

BUILDLINK_TREE+=	imap-uw

.if !defined(IMAP_UW_BUILDLINK3_MK)
IMAP_UW_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.imap-uw+=	imap-uw>=2007dnb1
BUILDLINK_ABI_DEPENDS.imap-uw+=	imap-uw>=2007fnb2
BUILDLINK_PKGSRCDIR.imap-uw?=	../../mail/imap-uw
. if ${OPSYS} == "Darwin"
BUILDLINK_LDFLAGS.imap-uw+=	-flat_namespace
. endif

.include "../../security/openssl/buildlink3.mk"
.endif # IMAP_UW_BUILDLINK3_MK

BUILDLINK_TREE+=	-imap-uw
