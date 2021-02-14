# $NetBSD: Makefile,v 1.2 2021/02/14 14:23:36 pin Exp $

DISTNAME=	kibi-0.2.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=ilai-deutel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ilai-deutel/kibi/
COMMENT=	Text editor in less than 1024 lines of code, written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/kibi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
