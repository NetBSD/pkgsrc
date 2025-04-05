# $NetBSD: Makefile,v 1.80.2.1 2025/04/05 20:44:58 maya Exp $

DISTNAME=		golint-20200301
PKGREVISION=		51
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
