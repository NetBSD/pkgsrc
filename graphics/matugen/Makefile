# $NetBSD: Makefile,v 1.12 2024/02/03 22:30:52 pin Exp $

DISTNAME=	matugen-2.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=InioX/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
