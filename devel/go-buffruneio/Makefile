# $NetBSD: Makefile,v 1.4 2018/03/04 15:52:13 bsiegert Exp $

DISTNAME=	go-buffruneio-0.2.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=pelletier/}
PKGREVISION=	1
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
