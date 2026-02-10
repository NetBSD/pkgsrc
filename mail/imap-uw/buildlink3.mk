# $NetBSD: buildlink3.mk,v 1.27 2026/02/10 02:14:16 gutteridge Exp $

BUILDLINK_TREE+=	imap-uw

.if !defined(IMAP_UW_BUILDLINK3_MK)
IMAP_UW_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.imap-uw+=	imap-uw>=2007dnb1
BUILDLINK_ABI_DEPENDS.imap-uw+=	imap-uw>=2007fnb16
BUILDLINK_PKGSRCDIR.imap-uw?=	../../mail/imap-uw
.if ${OPSYS} == "Darwin"
BUILDLINK_LDFLAGS.imap-uw+=	-flat_namespace
.endif

pkgbase :=      imap-uw
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.imap-uw:Mssl}

BUILDLINK_API_DEPENDS.openssl+=        openssl>=3.0
.  include "../../security/openssl/buildlink3.mk"
.endif # PKG_BUILD_OPTIONS
.endif # IMAP_UW_BUILDLINK3_MK

BUILDLINK_TREE+=	-imap-uw
