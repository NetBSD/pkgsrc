# $NetBSD: Makefile,v 1.57 2025/12/26 09:23:43 adam Exp $

DISTNAME=	timescaledb-tune-0.18.2
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
CATEGORIES=	databases
GITHUB_TAG=	v.${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb-tune
COMMENT=	Tune timescaledb to match system's CPU and memory resources
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/timescaledb-tune-${GITHUB_TAG}

.include "go-modules.mk"

GO_BUILD_PATTERN=	./cmd/timescaledb-tune/...

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
