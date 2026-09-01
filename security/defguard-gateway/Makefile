# $NetBSD: Makefile,v 1.9 2026/09/01 10:40:58 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-gateway-2.0.5
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	gateway
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# For internal crates.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}.tar.gz

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
NFTNL_REV=	abd34b08c53b88a47346da6362e360d522cf8ca2
DISTFILES+=	nftnl-${NFTNL_REV}.tar.gz

SITES.nftnl-${NFTNL_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=defguard/}nftnl-rs/archive/${NFTNL_REV}.tar.gz

RUST_REQ=	1.95

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-gateway ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
