# $NetBSD: Makefile,v 1.15 2025/05/06 20:09:56 pin Exp $

DISTNAME=	trippy-0.13.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fujiapple852/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fujiapple852/trippy/
COMMENT=	Network diagnostic tool
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.78.0

INSTALLATION_DIRS=	bin share/examples/trippy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/trip \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/trippy-config-sample.toml \
		${DESTDIR}${PREFIX}/share/examples/trippy

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
