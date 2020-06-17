# $NetBSD: Makefile,v 1.2 2020/06/17 09:54:14 bsiegert Exp $

DISTNAME=	goldmark-1.1.30
PKGNAME=	go-${DISTNAME}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=yuin/}
CATEGORIES=	textproc
GITHUB_PROJECT=	goldmark
GITHUB_TAG=	v${PKGVERSION_NOREV}
# DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/yuin/goldmark/
COMMENT=	CommonMark compliant Markdown parser in Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/yuin/goldmark

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
