# $NetBSD: Makefile,v 1.9 2022/04/17 22:56:22 pin Exp $

DISTNAME=	hgrep-0.2.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rhysd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/rhysd/hgrep/
COMMENT=	Grep with human-friendly search output
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		ripgrep syntect-printer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hgrep \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
