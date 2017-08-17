# $NetBSD: Makefile,v 1.1 2017/08/17 01:18:25 gavan Exp $

DISTNAME=	go-buffruneio-0.2.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=pelletier/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pelletier/go-buffruneio
COMMENT=	Buffruneio is a wrapper around bufio to provide buffered runes access with unlimited unreads.
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/pelletier/go-buffruneio

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

