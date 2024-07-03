# $NetBSD: Makefile,v 1.7 2024/07/03 06:59:31 bsiegert Exp $

DISTNAME=	sops-3.8.1
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=getsops/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/getsops/sops
COMMENT=	Simple and flexible tool for managing secrets
LICENSE=	mpl-2.0

GO_BUILD_PATTERN+=	./cmd/sops

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
