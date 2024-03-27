# $NetBSD: Makefile,v 1.19 2024/03/27 09:49:50 pin Exp $

DISTNAME=	dust-1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bootandy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/bootandy/dust/
COMMENT=	More intuitive version of du in rust
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/examples/dust

post-install:
	${INSTALL_MAN} ${WRKSRC}/man-page/dust.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dust.1
	${INSTALL_DATA} ${WRKSRC}/config/config.toml \
		${DESTDIR}${PREFIX}/share/examples/dust

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
