# $NetBSD: Makefile,v 1.7 2026/07/13 07:29:18 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-proxy-2.0.2
GITHUB_PROJECT=	proxy

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# Building web requires pnpm, which can't be easily build.
EXTRA_DIST+=	${DISTNAME}-web-dist${EXTRACT_SUFX}
# For internal crates.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-proxy ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
