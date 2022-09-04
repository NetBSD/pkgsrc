# $NetBSD: Makefile,v 1.21 2022/09/04 11:48:12 tnn Exp $

DISTNAME=	timescaledb-tune-0.14.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb-tune
COMMENT=	Tune timescaledb to match system's CPU and memory resources
LICENSE=	apache-2.0

.include "go-modules.mk"

GO_BUILD_PATTERN=	./cmd/timescaledb-tune/...

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
