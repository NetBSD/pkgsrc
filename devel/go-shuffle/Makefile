# $NetBSD: Makefile,v 1.27 2020/11/08 21:59:22 bsiegert Exp $

DISTNAME=	go-shuffle-0.0.20170808
MASTER_SITES=	${MASTER_SITE_GITHUB:=shogo82148/}
PKGREVISION=	24
CATEGORIES=	devel
GITHUB_TAG=	59829097ff3b062427a69e2c461ef60523e37280

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shogo82148/go-shuffle
COMMENT=	Primitives for shuffling slices and user-defined collections
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/shogo82148/go-shuffle

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
