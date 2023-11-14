# $NetBSD: Makefile,v 1.6 2023/11/14 21:06:42 pin Exp $

DISTNAME=	matugen-0.11.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=InioX/}
GITHUB_TAG=	matugen-v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/InioX/matugen/
COMMENT=	Material you color generation tool
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

INSTALLATION_DIRS=	share/examples/matugen

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/config.toml \
		${DESTDIR}${PREFIX}/share/examples/matugen

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
