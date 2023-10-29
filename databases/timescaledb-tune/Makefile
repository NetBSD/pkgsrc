# $NetBSD: Makefile,v 1.38 2023/10/29 14:48:08 bsiegert Exp $

DISTNAME=	timescaledb-tune-0.14.3
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
PKGREVISION=	9
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
