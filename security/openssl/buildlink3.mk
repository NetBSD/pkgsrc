# $NetBSD: buildlink3.mk,v 1.40 2009/03/20 19:25:21 joerg Exp $

BUILDLINK_TREE+=	openssl

.if !defined(OPENSSL_BUILDLINK3_MK)
OPENSSL_BUILDLINK3_MK:=

.  include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.6m
BUILDLINK_ABI_DEPENDS.openssl+=	openssl>=0.9.8g
BUILDLINK_PKGSRCDIR.openssl?=	../../security/openssl

# Ensure that -lcrypt comes before -lcrypto when linking so that the
# system crypt() routine is used.
#
WRAPPER_REORDER_CMDS+=	reorder:l:crypt:crypto

SSLBASE=	${BUILDLINK_PREFIX.openssl}
BUILD_DEFS+=	SSLBASE

pkgbase := openssl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.openssl:Mrsaref)
.  include "../../security/rsaref/buildlink3.mk"
.endif
.endif # OPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openssl
