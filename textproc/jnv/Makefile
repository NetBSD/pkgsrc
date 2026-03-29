# $NetBSD: Makefile,v 1.5 2026/03/29 17:04:56 wiz Exp $

DISTNAME=	jnv-0.7.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ynqa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nonaka@NetBSD.org
HOMEPAGE=	https://github.com/ynqa/jnv
COMMENT=	Interactive JSON viewer and jq filter editor
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin share/doc/jnv share/doc/jnv/assets

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jnv \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/CODE_OF_CONDUCT.md \
		${DESTDIR}${PREFIX}/share/doc/jnv
	${INSTALL_DATA} ${WRKSRC}/CONTRIBUTING.md \
		${DESTDIR}${PREFIX}/share/doc/jnv
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/jnv
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/jnv
	${INSTALL_DATA} ${WRKSRC}/assets/jnv-dark.svg \
		${DESTDIR}${PREFIX}/share/doc/jnv/assets
	${INSTALL_DATA} ${WRKSRC}/assets/jnv-light.svg \
		${DESTDIR}${PREFIX}/share/doc/jnv/assets

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
