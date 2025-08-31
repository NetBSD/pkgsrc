# $NetBSD: Makefile,v 1.40 2025/08/31 10:02:46 bsiegert Exp $

GITHUB_PROJECT=	go-tools
GITHUB_TAG=	2025.1.1
DISTNAME=	go-tools-${GITHUB_TAG}
PKGNAME=	go-staticcheck-${GITHUB_TAG}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dominikh/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://staticcheck.dev/
COMMENT=	Advanced Go linter
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/...
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/* ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
