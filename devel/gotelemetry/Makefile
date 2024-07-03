# $NetBSD: Makefile,v 1.9 2024/07/03 06:59:22 bsiegert Exp $

GITHUB_PROJECT=	telemetry
GITHUB_TAG=	config/v0.8.0
DISTNAME=	telemetry-config-v0.8.0
PKGNAME=	go${DISTNAME:S/-config-v/-/}
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://telemetry.go.dev/
COMMENT=	Tool for managing Go telemetry data and settings
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

GO_BUILD_PATTERN=	./cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
