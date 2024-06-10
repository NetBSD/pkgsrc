# $NetBSD: Makefile,v 1.2 2024/06/10 16:58:27 thorpej Exp $

# There is no tag on Github for 0.3.0, but that's what the program
# claims to be when you run it.
GALETTE_VERSION=0.3.0.0.2024.03.08

DISTNAME=	galette-${GALETTE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=simon-frankau/}
GITHUB_TAG=	af529870729b1da8794b002cd522f5bf2d53f230

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/simon-frankau/galette
COMMENT=	A GAL assembler, largely galasm-compatible and written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/galette \
	    ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
