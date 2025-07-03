# $NetBSD: Makefile,v 1.1 2025/07/03 13:32:29 wiz Exp $

DISTNAME=	resvg-0.45.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=linebender/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/linebender/resvg/
COMMENT=	SVG rendering library and tool
LICENSE=	apache-2.0 OR mit

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/resvg ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
