# $NetBSD: Makefile,v 1.5 2026/05/05 18:00:35 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-gateway-2.0.1
GITHUB_PROJECT=	gateway

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# For defguard-version crate.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}${EXTRACT_SUFX}

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
NFTNL_REV=	a5cf4c9965118e27795f4ad94ea5fbbde2687ff7
DISTFILES+=	nftnl-${NFTNL_REV}.tar.gz

SITES.nftnl-${NFTNL_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=defguard/}nftnl-rs/archive/${NFTNL_REV}.tar.gz

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-gateway ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
