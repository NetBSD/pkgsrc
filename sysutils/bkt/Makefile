# $NetBSD: Makefile,v 1.1 2022/02/01 19:17:29 pin Exp $

DISTNAME=	bkt-0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dimo414/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/dimo414/bkt/
COMMENT=	Subprocess caching utility
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bkt ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
