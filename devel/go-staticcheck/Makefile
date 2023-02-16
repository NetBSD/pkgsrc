# $NetBSD: Makefile,v 1.16 2023/02/16 15:02:10 bsiegert Exp $

GITHUB_PROJECT=	go-tools
GITHUB_TAG=	2022.1
DISTNAME=	go-tools-2022.1
PKGNAME=	go-staticcheck-${GITHUB_TAG}
PKGREVISION=	11
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
