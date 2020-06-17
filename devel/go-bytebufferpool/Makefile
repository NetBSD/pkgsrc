# $NetBSD: Makefile,v 1.8 2020/06/17 09:54:08 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	go-bytebufferpool-1.0.0
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=valyala/}
GITHUB_PROJECT=	bytebufferpool

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/valyala/bytebufferpool/
COMMENT=	Implementation of a pool of byte buffers with anti-memory-waste protection for Go
LICENSE=	mit

GO_SRCPATH=	github.com/valyala/bytebufferpool
GO_DIST_BASE=	bytebufferpool-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
