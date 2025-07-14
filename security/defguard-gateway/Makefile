# $NetBSD: Makefile,v 1.1 2025/07/14 05:36:04 adam Exp $

.include "../../security/defguard/version.mk"

DISTNAME=	defguard-gateway-${DEFGUARD_VERSION}
GITHUB_PROJECT=	gateway

COMMENT=	True Zero-Trust WireGuard VPN with 2FA/MFA

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
NFTNL_REV=	1a1147271f43b9d7182a114bb056a5224c35d38f
DISTFILES+=	nftnl-${NFTNL_REV}.tar.gz

SITES.nftnl-${NFTNL_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=defguard/}nftnl-rs/archive/${NFTNL_REV}.tar.gz

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/defguard-gateway ${DESTDIR}${PREFIX}/bin/

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
