# $NetBSD: Makefile,v 1.29 2024/02/07 14:50:47 bsiegert Exp $

GITHUB_PROJECT=	go-tools
GITHUB_TAG=	2023.1.6
DISTNAME=	go-tools-${GITHUB_TAG}
PKGNAME=	go-staticcheck-${GITHUB_TAG}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dominikh/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/dominikh/go-tools/
COMMENT=	Advanced Go linter
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/...
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/* ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
