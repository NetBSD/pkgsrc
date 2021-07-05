# $NetBSD: Makefile,v 1.7 2021/07/05 09:08:22 pin Exp $

DISTNAME=	navi-2.16.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=denisidoro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/denisidoro/navi/
COMMENT=	Interactive cheatsheet tool for the CLI and application launchers
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=		c	# rust, but needs a toolchain to link

DEPENDS+=	fzf-[0-9]*:../../sysutils/fzf

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/navi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
