# $NetBSD: Makefile,v 1.1 2016/07/14 20:01:06 bsiegert Exp $

DISTNAME=	gocheck-20160125
CATEGORIES=	wip www
GITHUB_PROJECT=	check
GITHUB_TAG=	v1
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-check/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://labix.org/gocheck
COMMENT=	Rich testing support for Go
LICENSE=	apache-2.0

GO_SRCPATH=	gopkg.in/check.v1
GO_DIST_BASE=	${GITHUB_PROJECT}-1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
