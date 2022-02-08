# $NetBSD: Makefile,v 1.45 2022/02/08 12:37:05 pin Exp $

DISTNAME=	macchina-6.0.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Macchina-CLI/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Macchina-CLI/macchina/
COMMENT=	System information frontend with emphasis on performance
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man7 share/examples/macchina

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/macchina ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/macchina.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/macchina.1
	${INSTALL_MAN} ${WRKSRC}/doc/macchina.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/macchina.7
	${INSTALL_DATA} ${WRKSRC}/macchina.toml ${DESTDIR}${PREFIX}/share/examples/macchina
	${INSTALL_DATA} ${WRKSRC}/contrib/themes/Lithium.toml ${DESTDIR}${PREFIX}/share/examples/macchina

DEPENDS+=	wmctrl-[0-9]*:../../wm/wmctrl

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
