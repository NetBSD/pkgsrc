# $NetBSD: Makefile,v 1.35 2024/02/07 14:51:01 bsiegert Exp $

DISTNAME=	miller-6.9.0
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
	
GO_BUILD_PATTERN+=	github.com/johnkerl/miller/cmd/mlr

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
