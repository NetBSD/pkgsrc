# $NetBSD: Makefile,v 1.3 2021/07/05 08:47:45 pin Exp $

DISTNAME=	pastel-0.8.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/pastel/
COMMENT=	Command-line tool to generate, analyze, convert and manipulate colors
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=			c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pastel ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
