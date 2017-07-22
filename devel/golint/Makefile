# $NetBSD: Makefile,v 1.9 2017/07/22 19:32:41 wiz Exp $

DISTNAME=		golint-20170228
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		lint
GITHUB_TAG=		cb00e56

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Linter for Go source files
LICENSE=		modified-bsd

GO_SRCPATH=		github.com/golang/lint
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

CHECK_RELRO_SKIP+=	bin/golint

.include "../../lang/go/go-package.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
