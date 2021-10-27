# $NetBSD: Makefile,v 1.3 2021/10/27 18:49:43 pin Exp $

DISTNAME=	hgrep-0.1.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rhysd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/rhysd/hgrep/
COMMENT=	Grep with human-friendly search output
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hgrep ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
