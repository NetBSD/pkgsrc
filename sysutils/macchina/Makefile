# $NetBSD: Makefile,v 1.35 2021/10/18 09:17:26 pin Exp $

DISTNAME=	macchina-2.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Macchina-CLI/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Macchina-CLI/macchina/
COMMENT=	Basic system information fetcher
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin share/examples/macchina

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/macchina ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/macchina.toml ${DESTDIR}${PREFIX}/share/examples/macchina

DEPENDS+=	wmctrl-[0-9]*:../../wm/wmctrl

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
