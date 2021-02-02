# $NetBSD: Makefile,v 1.3 2021/02/02 18:46:43 pin Exp $

DISTNAME=	sfm-0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Harunx9/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Harunx9/sfm/
COMMENT=	Simple file manager
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin share/doc/sfm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sfm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/sfm

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
