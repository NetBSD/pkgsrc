# $NetBSD: Makefile,v 1.2 2023/08/10 14:13:41 pin Exp $

DISTNAME=	matugen-0.9.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=InioX/}
GITHUB_PROJECT=	Matugen
GITHUB_TAG=	matugen-v${PKGVERSION_NOREV}

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
