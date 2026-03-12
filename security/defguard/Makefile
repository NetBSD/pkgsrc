# $NetBSD: Makefile,v 1.4 2026/03/12 12:19:38 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-${DEFGUARD_VERSION}

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# Building web requires pnpm, which can't be easily build.
EXTRA_DIST+=	${DISTNAME}-web-dist${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
