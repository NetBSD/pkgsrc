# $NetBSD: Makefile,v 1.1 2021/03/03 12:16:54 pin Exp $

DISTNAME=	rates-0.2.0
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=lunush/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/lunush/rates/
COMMENT=	Currency exchange rates in your terminal
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rates ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
