# $NetBSD: Makefile,v 1.1 2026/09/24 15:50:53 leot Exp $

DISTNAME=	harper-2.11.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Automattic/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://writewithharper.com/
COMMENT=	Offline, privacy-first grammar checker
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

do-install:
.for f in harper-cli harper-ls
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${f} \
		${DESTDIR}${PREFIX}/bin
.endfor

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
