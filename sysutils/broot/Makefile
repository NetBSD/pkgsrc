# $NetBSD: Makefile,v 1.24 2021/06/24 08:44:50 pin Exp $

DISTNAME=	broot-1.6.0
# Do not update this package. Newer versions require Rust-1.53.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Canop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://dystroy.org/broot/
COMMENT=	New way to see and navigate directory trees
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c	# rust, but needs a toolchain to link
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/broot ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/page ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/broot.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
