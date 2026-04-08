# $NetBSD: Makefile,v 1.8 2026/04/08 05:44:53 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	buf-1.45.0
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bufbuild/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bufbuild/buf/
COMMENT=	CLI tool for working with Protocol Buffers
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cmd/buf

DOCKER_VER=	v27.3.1+incompatible

GO_MODULE_EXTRACT+=	github.com_docker_docker_@v_${DOCKER_VER}.zip

post-extract:
	${CP} ${WRKDIR}/.goproxy/github.com/docker/docker/@v/v27.3.1+incompatible.mod ${WRKDIR}/github.com/docker/docker@${DOCKER_VER}/go.mod
.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
