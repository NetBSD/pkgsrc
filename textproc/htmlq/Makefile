# $NetBSD: Makefile,v 1.2 2023/05/17 21:44:11 wiz Exp $

DISTNAME=	htmlq-0.4.0
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgdm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgdm/htmlq/
COMMENT=	Parse and extract HTML from the command line
LICENSE=	mit

INSTALLATION_DIRS+=	share/doc/htmlq

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/htmlq

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
