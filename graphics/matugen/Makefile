# $NetBSD: Makefile,v 1.3 2023/08/13 19:33:57 pin Exp $

DISTNAME=	matugen-0.9.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=InioX/}
GITHUB_PROJECT=	Matugen
#GITHUB_TAG=	matugen-v${PKGVERSION_NOREV}
GITHUB_TAG=	8aeb6bbad7d3a240c3d24cabbe885448ec16a9e5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/InioX/Matugen/
COMMENT=	Material you color generation tool
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

INSTALLATION_DIRS=	share/examples/matugen

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/config.toml \
		${DESTDIR}${PREFIX}/share/examples/matugen

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
