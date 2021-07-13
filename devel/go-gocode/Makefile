# $NetBSD: Makefile,v 1.29 2021/07/13 11:36:42 bsiegert Exp $

DISTNAME=	gocode-20170907
PKGNAME=	go-${DISTNAME}
PKGREVISION=	28
MASTER_SITES=	${MASTER_SITE_GITHUB:=nsf/}
CATEGORIES=	devel
GITHUB_PROJECT=	gocode
GITHUB_TAG=	v.${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/nsf/gocode
COMMENT=	Autocompletion daemon for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/nsf/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
