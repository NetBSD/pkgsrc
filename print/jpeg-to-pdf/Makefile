# $NetBSD: Makefile,v 1.1 2021/02/23 18:18:53 pin Exp $

DISTNAME=	jpeg-to-pdf-0.2.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=Quantaly/}
GITHUB_PROJECT=	jpeg-to-pdf
GITHUB_TAG=	7250b2f244662c6d0905ca4ede716ab7afe4960b

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Quantaly/jpeg-to-pdf/
COMMENT=	Creates pdfs from jpeg images
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cli ${DESTDIR}${PREFIX}/bin/jpeg-to-pdf

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
