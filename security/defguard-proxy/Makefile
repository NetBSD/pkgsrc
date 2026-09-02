# $NetBSD: Makefile,v 1.9 2026/09/02 19:04:14 wiz Exp $

PKGREVISION= 1
.include "../../security/defguard/version.mk"

DISTNAME=	defguard-proxy-2.0.2
GITHUB_PROJECT=	proxy
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}-proto${EXTRACT_SUFX}
# Building web requires pnpm, which can't be easily build.
EXTRA_DIST+=	${DISTNAME}-web-dist${EXTRACT_SUFX}
# For internal crates.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin

post-extract:
	${RMDIR} ${WRKSRC}/proto && ${LN} -f -s ${WRKDIR}/proto ${WRKSRC}/proto

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-proxy ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
