# $NetBSD: Makefile,v 1.9 2021/10/08 18:55:09 bsiegert Exp $

DISTNAME=	direnv-2.27.0
PKGREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=direnv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
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
