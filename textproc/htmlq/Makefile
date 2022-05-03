# $NetBSD: Makefile,v 1.1 2022/05/03 19:21:29 pin Exp $

DISTNAME=	htmlq-0.4.0
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgdm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgdm/htmlq/
COMMENT=	Parse and extract HTML from the command line
LICENSE=	mit

INSTALLATION_DIRS+=	bin share/doc/htmlq

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/htmlq ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/htmlq

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
