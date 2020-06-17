# $NetBSD: Makefile,v 1.3 2020/06/17 09:54:09 bsiegert Exp $

DISTNAME=	go-wordwrap-1.0.0
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitchellh/}
CATEGORIES=	devel
GITHUB_PROJECT=	go-wordwrap
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitchellh/go-wordwrap
COMMENT=	Go library for wrapping words in a string
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/mitchellh/go-wordwrap

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
