# $NetBSD: Makefile,v 1.21 2020/04/12 11:01:32 bsiegert Exp $

DISTNAME=	consul-api-0.0.20150107
PKGNAME=	go-${DISTNAME}
PKGREVISION=	18
MASTER_SITES=	${MASTER_SITE_GITHUB:=armon/}
CATEGORIES=	devel
GITHUB_TAG=	dcfedd50ed5334f96adee43fc88518a4f095e15c
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/armon/consul-api
COMMENT=	Golang API client for Consul
LICENSE=	mpl-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/armon/consul-api

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
