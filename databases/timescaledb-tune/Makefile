# $NetBSD: Makefile,v 1.22 2022/09/07 09:32:23 bsiegert Exp $

DISTNAME=	timescaledb-tune-0.14.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
PKGREVISION=	1
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
