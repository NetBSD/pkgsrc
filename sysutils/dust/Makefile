# $NetBSD: Makefile,v 1.10 2022/08/24 05:18:15 pin Exp $

DISTNAME=	dust-0.8.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bootandy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/bootandy/dust/
COMMENT=	More intuitive version of du in rust
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/dust \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
