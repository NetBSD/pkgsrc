# $NetBSD: Makefile,v 1.26 2022/11/02 19:39:52 bsiegert Exp $

DISTNAME=	timescaledb-tune-0.14.2
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
