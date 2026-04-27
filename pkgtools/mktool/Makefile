# $NetBSD: Makefile,v 1.30 2026/04/27 08:17:24 jperkin Exp $

DISTNAME=	mktool-1.5.8
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	High performance alternatives for pkgsrc/mk
LICENSE=	isc

USE_LANGUAGES=	c
RUST_REQ=	1.85.1

#
# For consistency in pkgsrc this build switches to using native-certs, i.e.
# openssl for the most part, and requires a certificate store to be configured.
#
# If you want to build a portable binary that bundles the webpki-roots certs
# and uses rustls then simply 'cargo install mktool' to use the defaults.
#
CARGO_NO_DEFAULT_FEATURES=	yes
CARGO_FEATURES+=		native-certs

.include "../../mk/bsd.prefs.mk"

# Use OpenSSL except on Darwin where native-tls uses Security.framework.
.if ${OPSYS} != "Darwin"
.include "../../security/openssl/buildlink3.mk"
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
.endif

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
