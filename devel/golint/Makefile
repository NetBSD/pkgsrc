# $NetBSD: Makefile,v 1.57 2022/10/05 11:32:57 bsiegert Exp $

DISTNAME=		golint-20200301
PKGREVISION=		27
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		lint
GITHUB_TAG=		738671d3881b9731cc63024d5d88cf28db875626

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Linter for Go source files
LICENSE=		modified-bsd

.include "go-modules.mk"

GO_BUILD_PATTERN=	./golint

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
