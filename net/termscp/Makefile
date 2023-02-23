# $NetBSD: Makefile,v 1.2 2023/02/23 07:36:27 pin Exp $

DISTNAME=	termscp-0.11.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=veeso/}
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://veeso.github.io/termscp/
COMMENT=	Feature rich TUI file transfer and explorer
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/termscp \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
