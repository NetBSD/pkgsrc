# $NetBSD: Makefile,v 1.15 2022/04/10 15:41:01 pin Exp $

DISTNAME=	felix-0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyoheiu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kyoheiu/felix/
COMMENT=	TUI file manager with vim-like key mapping
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fx \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
