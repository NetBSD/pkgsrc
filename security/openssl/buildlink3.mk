# $NetBSD: buildlink3.mk,v 1.38 2008/01/05 20:41:25 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENSSL_BUILDLINK3_MK:=	${OPENSSL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openssl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenssl}
BUILDLINK_PACKAGES+=	openssl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}openssl

.if !empty(OPENSSL_BUILDLINK3_MK:M+)

.  include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.6m
.  if defined(USE_FEATURES.openssl) && !empty(USE_FEATURES.openssl:Mthreads)
BUILDLINK_ABI_DEPENDS.openssl+=	openssl>=0.9.7inb4
.  else
BUILDLINK_ABI_DEPENDS.openssl+=	openssl>=0.9.7inb1
.  endif
BUILDLINK_PKGSRCDIR.openssl?=	../../security/openssl

# Ensure that -lcrypt comes before -lcrypto when linking so that the
# system crypt() routine is used.
#
WRAPPER_REORDER_CMDS+=	reorder:l:crypt:crypto

SSLBASE=	${BUILDLINK_PREFIX.openssl}
BUILD_DEFS+=	SSLBASE
.endif	# OPENSSL_BUILDLINK3_MK

pkgbase := openssl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.openssl:Mrsaref)
.  include "../../security/rsaref/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
