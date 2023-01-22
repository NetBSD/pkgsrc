# $NetBSD: Makefile,v 1.1 2023/01/22 09:01:46 pin Exp $

DISTNAME=	garden-0.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=davvid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://davvid.github.io/garden/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/garden \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
