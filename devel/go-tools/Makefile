# $NetBSD: Makefile,v 1.3 2015/12/28 11:58:12 bsiegert Exp $
#

DISTNAME=		tools
PKGNAME=		go-tools-1.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		d02228d

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Tools for use with Go, including godoc
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/tools
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

USE_TOOLS+=		bash
REPLACE_BASH=		cmd/godoc/setup-godoc-app.bash

.include "../../lang/go/go-package.mk"
.include "../../devel/google-api-go-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
