# $NetBSD: Makefile,v 1.4 2023/01/28 13:10:22 pin Exp $

DISTNAME=	fsrx-1.0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=coloradocolby/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
