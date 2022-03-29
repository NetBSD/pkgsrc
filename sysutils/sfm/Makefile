# $NetBSD: Makefile,v 1.11 2022/03/29 10:40:45 pin Exp $

DISTNAME=	sfm-0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Harunx9/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Harunx9/sfm/
COMMENT=	Simple file manager
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin share/doc/sfm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sfm \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/sfm

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
