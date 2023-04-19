# $NetBSD: Makefile,v 1.1 2023/04/19 17:25:56 thorpej Exp $

# There is no tag on Github for 0.3.0, but that's what the program
# claims to be when you run it.
GALETTE_VERSION=0.3.0

DISTNAME=	galette-${GALETTE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=simon-frankau/}
GITHUB_TAG=	e28809d16858ff89d7e62dc7e50c07edcc9e5189

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
