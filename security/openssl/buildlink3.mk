# $NetBSD: buildlink3.mk,v 1.55 2020/01/18 21:48:23 jperkin Exp $

BUILDLINK_TREE+=	openssl

.if !defined(OPENSSL_BUILDLINK3_MK)
OPENSSL_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.1.1
BUILDLINK_ABI_DEPENDS.openssl+=	openssl>=1.1.1dnb2
BUILDLINK_PKGSRCDIR.openssl?=	../../security/openssl

# Ensure that -lcrypt comes before -lcrypto when linking so that the
# system crypt() routine is used.
#
.if ${OPSYS} != "Cygwin"
WRAPPER_REORDER_CMDS+=	reorder:l:crypt:crypto
.endif

SSLBASE=	${BUILDLINK_PREFIX.openssl}
BUILD_DEFS+=	SSLBASE

.endif # OPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openssl
