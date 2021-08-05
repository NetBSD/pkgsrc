# $NetBSD: Makefile,v 1.8 2021/08/05 08:47:25 pin Exp $

DISTNAME=	yaydl-0.6.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dertuxmalwieder/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://code.rosaelefanten.org/yaydl/home
COMMENT=	Yet another youtube down loader
LICENSE=	cddl-1.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yaydl ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
