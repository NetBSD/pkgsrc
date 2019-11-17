# $NetBSD: Makefile,v 1.19.2.1 2019/11/17 08:30:11 spz Exp $

DISTNAME=	go-ratelimit-0.0.20151125
PKGREVISION=	18
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=juju/}
GITHUB_PROJECT=	ratelimit
GITHUB_TAG=	77ed1c8a01217656d2080ad51981f6e99adaa177

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/juju/ratelimit
COMMENT=	Efficient token-bucket-based rate limiter package
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/juju/ratelimit

.include "../../devel/go-check/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
