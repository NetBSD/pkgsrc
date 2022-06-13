# $NetBSD: Makefile,v 1.2 2022/06/13 20:47:10 pin Exp $

DISTNAME=	fsrx-1.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=coloradocolby/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/coloradocolby/fsrx/
COMMENT=	Flow state reading in the terminal
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fsrx \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
