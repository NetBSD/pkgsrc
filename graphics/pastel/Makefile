# $NetBSD: Makefile,v 1.7 2023/07/19 06:00:55 pin Exp $

DISTNAME=	pastel-0.9.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/pastel/
COMMENT=	Command-line tool to generate, analyze, convert and manipulate colors
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pastel \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
