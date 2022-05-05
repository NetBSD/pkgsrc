# $NetBSD: Makefile,v 1.2 2022/05/05 06:59:17 pin Exp $

DISTNAME=	angle-grinder-0.18.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rcoh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rcoh/angle-grinder/
COMMENT=	Slice and dice logs on the command line
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/agrind \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
