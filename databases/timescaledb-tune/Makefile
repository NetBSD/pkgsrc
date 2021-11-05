# $NetBSD: Makefile,v 1.10 2021/11/05 20:02:40 bsiegert Exp $

DISTNAME=	timescaledb-tune-0.11.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
PKGREVISION=	4
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
