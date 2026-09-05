# $NetBSD: Makefile,v 1.7 2026/09/05 05:08:23 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-${DEFGUARD_VERSION}

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

CARGO_GITHUB_CRATES=	DefGuard ldap3 65ae9ad320770c63f366233ebe121534e16b59a7#65ae9ad3

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
