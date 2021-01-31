# $NetBSD: Makefile,v 1.3 2021/01/31 14:52:06 pin Exp $

DISTNAME=	yaydl-0.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dertuxmalwieder/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://code.rosaelefanten.org/yaydl/index
COMMENT=	Yet another youtube down loader
LICENSE=	cddl-1.0

.include "cargo-depends.mk"

USE_LANGUAGES+=			c	# rust, but needs a toolchain to link
USE_TOOLS+=			pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yaydl ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
