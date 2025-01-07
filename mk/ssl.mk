#	$NetBSD: ssl.mk,v 1.1 2025/01/07 19:18:07 riastradh Exp $

# SSL/TLS-related paths for trust anchors, certificates, private keys.
#
# Packages should normally include security/openssl/buildlink3.mk or
# similar, not mk/ssl.mk, for these variables.
#
# System-defined variables:
#
# SSLDIR
#	Path to directory where TLS-related files, including trust
#	anchors (CA certificates) and sometimes private keys, are
#	stored.
#
#	Normally SSLDIR is defined by mk/ssldir.mk, but it may be
#	defined differently by security/openssl/builtin.mk when using
#	OpenSSL from pkgsrc instead of builtin.
#
# SSLCERTS
#	Path to directory of TLS trust anchors in OpenSSL hashed
#	certificate format (see openssl_rehash(1)).
#
# SSLCERTBUNDLE
#	Path to file of TLS trust anchors in concatenated PEM bundle
#	format.  Undefined or empty if the host OS does not ship one.
#
# SSLKEYS
#	Path to directory of per-service TLS private keys.
#

.ifndef SSLDIR
.  include "ssldir.mk"
.endif

.include "bsd.fast.prefs.mk"

SSLCERTS=	${SSLDIR}/certs
# Some systems use CA bundles instead of files and hashed symlinks.
# Continue to define SSLCERTS because it's unclear if that's the
# directory that has one file per cert, or the directory that contains
# trust anchor config in some fortm.
.if ${OPSYS} == "NetBSD"
SSLCERTBUNDLE=	${SSLDIR}/certs/ca-certificates.crt
.elif exists(${_CROSS_DESTDIR:U}${SSLDIR}/certs/ca-bundle.crt)
SSLCERTBUNDLE=	${SSLDIR}/certs/ca-bundle.crt
.endif
SSLKEYS=	${SSLDIR}/private

BUILD_DEFS+=	SSLDIR SSLCERTS SSLCERTBUNDLE SSLKEYS
