# $NetBSD: Makefile,v 1.1 2023/05/11 05:27:50 adam Exp $

DISTNAME=	cargo-cache-0.8.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=matthiaskrgr/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matthiaskrgr/cargo-cache
COMMENT=	Display information on the cargo cache
LICENSE=	mit OR apache-2.0

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-cache ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
