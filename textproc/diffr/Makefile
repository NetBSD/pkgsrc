# $NetBSD: Makefile,v 1.1 2020/11/26 21:43:43 pin Exp $

DISTNAME=	diffr-0.1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mookid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/mookid/diffr/
COMMENT=	Yet another diff highlighting tool
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/diffr ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
