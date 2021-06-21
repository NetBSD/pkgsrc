# $NetBSD: Makefile,v 1.7 2021/06/21 07:11:55 pin Exp $

DISTNAME=	yaydl-0.6.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dertuxmalwieder/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://code.rosaelefanten.org/yaydl/home
COMMENT=	Yet another youtube down loader
LICENSE=	cddl-1.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yaydl ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
