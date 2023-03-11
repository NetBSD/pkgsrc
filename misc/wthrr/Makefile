# $NetBSD: Makefile,v 1.16 2023/03/11 22:07:11 pin Exp $

DISTNAME=	wthrr-0.10.0
CATEGORIES=	misc
MASTER_SITES=	https://static.crates.io/crates/wthrr/
EXTRACT_SUFX=	.crate

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
