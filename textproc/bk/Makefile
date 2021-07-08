# $NetBSD: Makefile,v 1.6 2021/07/08 13:21:12 pin Exp $

DISTNAME=	bk-0.5.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aeosynth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/aeosynth/bk/
COMMENT=	Terminal Epub reader
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bk ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
