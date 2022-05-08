# $NetBSD: Makefile,v 1.2 2022/05/08 10:16:58 pin Exp $

DISTNAME=	ctv-0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=angelina-tsuboi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/angelina-tsuboi/ctv/
COMMENT=	Configurable tree view
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ctv \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
