# $NetBSD: Makefile,v 1.12 2017/03/16 19:33:50 bsiegert Exp $
#

DISTNAME=		tools
PKGNAME=		go-tools-1.8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		2946dd1

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Tools for use with Go, including godoc
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/tools
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

USE_TOOLS+=		bash
REPLACE_BASH+=		cmd/godoc/setup-godoc-app.bash
REPLACE_BASH+=		cmd/oracle/emacs-test.bash

.include "../../lang/go/go-package.mk"
.include "../../devel/google-api-go-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
