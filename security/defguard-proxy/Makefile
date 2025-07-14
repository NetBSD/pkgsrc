# $NetBSD: Makefile,v 1.1 2025/07/14 05:36:33 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-proxy-${DEFGUARD_VERSION}
GITHUB_PROJECT=	proxy

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-proxy ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
