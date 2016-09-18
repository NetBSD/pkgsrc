# $NetBSD: Makefile,v 1.1 2016/09/18 16:57:51 kamil Exp $

DISTNAME=	2048-cli-0.9.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=tiehuis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tiehuis/2048-cli/
COMMENT=	The game 2048 for your Unix terminal
LICENSE=	mit

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2048 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/2048.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
