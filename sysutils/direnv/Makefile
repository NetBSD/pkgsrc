# $NetBSD: Makefile,v 1.26 2023/01/11 17:28:36 bsiegert Exp $

DISTNAME=	direnv-2.32.1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=direnv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://direnv.net/
COMMENT=	Environment switcher for the shell
LICENSE=	mit

.include "go-modules.mk"

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO} build -o direnv

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}/${PREFIX}/bin
	${INSTALL_MAN_DIR} ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/direnv ${DESTDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
