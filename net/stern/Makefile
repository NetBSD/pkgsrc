# $NetBSD: Makefile,v 1.38 2026/11/10 18:55:17 bsiegert Exp $

DISTNAME=	stern-1.30.0
PKGREVISION=	23
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=stern/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/stern/stern
COMMENT=	Multi pod and container log tailing for Kubernetes
LICENSE=	apache-2.0

# Do not build and install github.com/stern/stern/hack/update-readme
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
