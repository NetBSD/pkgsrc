# $NetBSD: Makefile,v 1.4 2026/03/12 12:21:15 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-proxy-1.6.3
GITHUB_PROJECT=	proxy

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# For defguard-version crate.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-proxy ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
