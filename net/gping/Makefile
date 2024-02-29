# $NetBSD: Makefile,v 1.5 2024/02/29 14:20:51 pin Exp $

DISTNAME=	gping-1.16.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=orf/}
GITHUB_TAG=	refs/tags/gping-v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/orf/gping/
COMMENT=	Ping, but with a graph
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=	${WRKDIR}/gping-gping-v${PKGVERSION_NOREV}

USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gping \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gping.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gping.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
