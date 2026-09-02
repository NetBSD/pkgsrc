# $NetBSD: Makefile,v 1.6 2026/09/02 19:04:14 wiz Exp $

PKGREVISION= 1
.include "../../security/defguard/version.mk"

DISTNAME=	defguard-${DEFGUARD_VERSION}
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}-proto${EXTRACT_SUFX}
# Building web requires pnpm, which can't be easily build.
EXTRA_DIST+=	${DISTNAME}-web-dist${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin

post-extract:
	${RMDIR} ${WRKSRC}/proto && ${LN} -f -s ${WRKDIR}/proto ${WRKSRC}/proto

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
