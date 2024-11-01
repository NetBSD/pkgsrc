# $NetBSD: Makefile,v 1.55 2024/11/01 16:37:35 pin Exp $

DISTNAME=	macchina-6.3.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Macchina-CLI/}
# does not contain the git submodules, please update GITHUB_SUBMODULES below
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Macchina-CLI/macchina/
COMMENT=	System information frontend with emphasis on performance
LICENSE=	mit

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

GITHUB_SUBMODULES+=	Macchina-CLI	color-to-tui 	9a1b684d92cc64994889e100575e38316a68670b	vendor/color-to-tui
GITHUB_SUBMODULES+=	Macchina-CLI	ansi-to-tui 	950d68067ed8c7f74469eb2fd996e04e1b931481	vendor/ansi-to-tui

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7 share/examples/macchina

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/macchina.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/macchina.1
	${INSTALL_MAN} ${WRKSRC}/doc/macchina.7 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/macchina.7
	${INSTALL_DATA} ${WRKSRC}/macchina.toml \
		${DESTDIR}${PREFIX}/share/examples/macchina
	${INSTALL_DATA} ${WRKSRC}/contrib/themes/Lithium.toml \
		${DESTDIR}${PREFIX}/share/examples/macchina

DEPENDS+=	wmctrl-[0-9]*:../../wm/wmctrl

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
