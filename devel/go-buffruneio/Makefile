# $NetBSD: Makefile,v 1.8 2018/12/19 15:47:05 bsiegert Exp $

DISTNAME=	go-buffruneio-0.2.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=pelletier/}
PKGREVISION=	5
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pelletier/go-buffruneio
COMMENT=	Wrapper around bufio to provide buffered runes access
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/pelletier/go-buffruneio

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
