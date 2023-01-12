# $NetBSD: Makefile,v 1.43 2023/01/12 00:18:11 tnn Exp $

DISTNAME=	promscale-0.17.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
CATEGORIES=	databases
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timescale/promscale
COMMENT=	TimescaleDB storage connector for Prometheus
LICENSE=	apache-2.0

.include "go-modules.mk"

GO_BUILD_PATTERN=	./cmd/promscale/...

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
