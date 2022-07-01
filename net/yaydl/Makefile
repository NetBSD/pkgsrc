# $NetBSD: Makefile,v 1.14 2022/07/01 06:55:38 pin Exp $

DISTNAME=	yaydl-8b8d3607ec
PKGNAME=	yaydl-0.10.1
CATEGORIES=	net
MASTER_SITES=	https://code.rosaelefanten.org/yaydl/tarball/0b14ea41d0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.rosaelefanten.org/yaydl/home
COMMENT=	Yet another youtube down loader
LICENSE=	cddl-1.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yaydl \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
