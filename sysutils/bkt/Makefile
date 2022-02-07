# $NetBSD: Makefile,v 1.2 2022/02/07 09:17:55 pin Exp $

DISTNAME=	bkt-0.5.2
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
