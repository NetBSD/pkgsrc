# $NetBSD: Makefile,v 1.6 2022/08/01 08:05:46 pin Exp $

DISTNAME=	dusage-0.3.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mihaigalos/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/mihaigalos/dusage/
COMMENT=	Command line disk usage information tool
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/dusage \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
