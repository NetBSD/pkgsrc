# $NetBSD: Makefile,v 1.5 2022/05/22 16:39:02 pin Exp $

DISTNAME=	dusage-0.3.0
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
