# $NetBSD: Makefile,v 1.2 2018/02/20 22:47:50 rillig Exp $

# Note: the version number is made up from the commit date since go tools
# have neither branches nor tags.

DISTNAME=	goyacc-0.20170314
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
CATEGORIES=	devel
GITHUB_PROJECT=	tools
GITHUB_TAG=	6185cb1f3105899cd34484c59407846bec0acc06

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://godoc.org/golang.org/x/tools/cmd/goyacc
COMMENT=	Yacc for the Go programming language
LICENSE=	modified-bsd

GO_SRCPATH=	x/tools/cmd/goyacc
GO_DIST_BASE=	tools-${GITHUB_TAG}/cmd/goyacc

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
