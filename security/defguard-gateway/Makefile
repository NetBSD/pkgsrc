# $NetBSD: Makefile,v 1.4 2026/03/12 12:20:32 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-gateway-1.6.3
GITHUB_PROJECT=	gateway

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# For defguard-version crate.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}${EXTRACT_SUFX}

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
NFTNL_REV=	1a1147271f43b9d7182a114bb056a5224c35d38f
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
