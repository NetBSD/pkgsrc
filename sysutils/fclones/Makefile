# $NetBSD: Makefile,v 1.1 2023/11/06 09:17:42 wiz Exp $

DISTNAME=	fclones-0.34.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=pkolaczk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pkolaczk/fclones/
COMMENT=	Efficient Duplicate File Finder
LICENSE=	mit

USE_LANGUAGES=	c

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fclones ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
