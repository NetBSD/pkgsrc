# $NetBSD: Makefile,v 1.10 2025/10/23 20:35:55 wiz Exp $

DISTNAME=	spotifyd-0.4.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Spotifyd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://github.com/Spotifyd/spotifyd/
COMMENT=	Open source Spotify client running as a UNIX daemon
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

RUST_REQ=	1.82.0

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

.include "options.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
