# $NetBSD: Makefile,v 1.14 2020/03/21 16:57:16 bsiegert Exp $

DISTNAME=	go-humanize-1.0.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=dustin/}
PKGREVISION=	13
CATEGORIES=	devel
GITHUB_PROJECT=	go-humanize
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dustin/go-humanize
COMMENT=	Go library for formatters for units to human friendly sizes
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/dustin/go-humanize

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
