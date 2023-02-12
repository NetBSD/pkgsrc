# $NetBSD: Makefile,v 1.44 2023/02/12 14:57:53 pin Exp $

DISTNAME=	felix-2.2.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyoheiu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://kyoheiu.dev/felix/
COMMENT=	TUI file manager with vim-like key mapping
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin share/examples/felix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fx \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/config.yaml \
		${DESTDIR}${PREFIX}/share/examples/felix

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
