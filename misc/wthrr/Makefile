# $NetBSD: Makefile,v 1.1 2022/08/15 08:47:18 pin Exp $

DISTNAME=	wthrr-the-weathercrab-0.1.3
PKGNAME=	wthrr-0.1.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tobealive/}
GITHUB_PROJECT=	wthrr-the-weathercrab
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tobealive/wthrr-the-weathercrab/
COMMENT=	Little helper for your terminal who knows about the weather
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wthrr \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
