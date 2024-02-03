# $NetBSD: Makefile,v 1.61 2024/02/03 22:21:57 pin Exp $

DISTNAME=	felix-2.12.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyoheiu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://kyoheiu.dev/felix/
COMMENT=	TUI file manager with vim-like key mapping
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	share/examples/felix

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.yaml \
		${DESTDIR}${PREFIX}/share/examples/felix

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
