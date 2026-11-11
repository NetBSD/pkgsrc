# $NetBSD: Makefile,v 1.31.2.2 2026/11/11 20:32:15 maya Exp $

DISTNAME=	sops-3.11.0
PKGREVISION=	12
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=getsops/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://getsops.io/
COMMENT=	Simple and flexible tool for managing secrets
LICENSE=	mpl-2.0

GO_BUILD_PATTERN+=	./cmd/sops

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
