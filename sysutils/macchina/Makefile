# $NetBSD: Makefile,v 1.22 2021/05/18 06:59:13 pin Exp $

DISTNAME=	macchina-0.8.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Macchina-CLI/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Macchina-CLI/macchina/
COMMENT=	Basic system information fetcher
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++

INSTALLATION_DIRS=	bin share/examples/macchina

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/macchina ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/macchina.toml ${DESTDIR}${PREFIX}/share/examples/macchina

DEPENDS+=	wmctrl-[0-9]*:../../wm/wmctrl

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
