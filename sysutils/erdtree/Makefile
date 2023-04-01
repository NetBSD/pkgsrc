# $NetBSD: Makefile,v 1.4 2023/04/01 15:57:20 pin Exp $

DISTNAME=	erdtree-1.7.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=solidiquis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/solidiquis/erdtree/
COMMENT=	Multi-threaded file-tree visualizer and disk usage analyzer
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/et \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
