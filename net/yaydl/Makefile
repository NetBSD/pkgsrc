# $NetBSD: Makefile,v 1.10 2022/05/17 18:36:51 pin Exp $

DISTNAME=	yaydl-512577aefc
PKGNAME=	yaydl-0.7.1
CATEGORIES=	net
MASTER_SITES=	https://code.rosaelefanten.org/yaydl/tarball/512577aefc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.rosaelefanten.org/yaydl/home
COMMENT=	Yet another youtube down loader
LICENSE=	cddl-1.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yaydl \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
