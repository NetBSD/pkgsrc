# $NetBSD: Makefile,v 1.13 2023/01/30 08:49:07 pin Exp $

DISTNAME=	dust-0.8.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bootandy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/bootandy/dust/
COMMENT=	More intuitive version of du in rust
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/dust

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/dust \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man-page/dust.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dust.1
	${INSTALL_DATA} ${WRKSRC}/config/config.toml \
		${DESTDIR}${PREFIX}/share/examples/dust

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
