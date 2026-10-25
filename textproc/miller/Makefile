# $NetBSD: Makefile,v 1.63 2026/10/25 20:33:00 drixter Exp $

DISTNAME=	miller-6.22.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/johnkerl/miller/
COMMENT=	Command-line CSV processor
LICENSE=	2-clause-bsd

USE_TOOLS+=	flex sed

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-configure:
	${MKDIR} ${DESTDIR}${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/mlr ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/mlr.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

GO_BUILD_PATTERN+=	github.com/johnkerl/miller/v6/cmd/mlr

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
