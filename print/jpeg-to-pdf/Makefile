# $NetBSD: Makefile,v 1.4 2021/08/03 08:55:03 pin Exp $

DISTNAME=	jpeg-to-pdf-0.2.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=Quantaly/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Quantaly/jpeg-to-pdf/
COMMENT=	Creates pdfs from jpeg images
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cli ${DESTDIR}${PREFIX}/bin/jpeg-to-pdf

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
