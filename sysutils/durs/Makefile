# $NetBSD: Makefile,v 1.1 2025/01/09 10:17:06 pin Exp $

DISTNAME=	durs-0.1.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=trinhminhtriet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trinhminhtriet/durs/
COMMENT=	Fast, intuitive disk usage analyzer
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/examples/durs

post-install:
	${INSTALL_MAN} ${WRKSRC}/man-page/durs.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/durs.1
	${INSTALL_DATA} ${WRKSRC}/config/config.toml \
		${DESTDIR}${PREFIX}/share/examples/durs

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
