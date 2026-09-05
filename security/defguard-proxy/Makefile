# $NetBSD: Makefile,v 1.10 2026/09/05 05:08:24 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-proxy-${DEFGUARD_VERSION}
GITHUB_PROJECT=	proxy

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# For internal crates.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}.tar.xz

WRKSRC=		${WRKDIR}/proxy-${DEFGUARD_VERSION}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-proxy ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
