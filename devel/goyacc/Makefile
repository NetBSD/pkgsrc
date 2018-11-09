# $NetBSD: Makefile,v 1.4 2018/11/09 20:51:46 rillig Exp $
#

DISTNAME=		goyacc
PKGNAME=		goyacc-20181109
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		tools
GITHUB_TAG=		92d8274bd7b8a4c65f24bafe401a029e58392704

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		https://godoc.org/golang.org/x/tools/cmd/goyacc
COMMENT=		Parser generator for Go programs
LICENSE=		modified-bsd

GO_DIST_BASE=		tools-${GITHUB_TAG}
GO_SRCPATH=		golang.org/x/tools
GO_BUILD_PATTERN=	golang.org/x/tools/cmd/goyacc

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
