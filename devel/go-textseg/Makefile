# $NetBSD: Makefile,v 1.12 2021/06/06 12:18:52 bsiegert Exp $

DISTNAME=	go-textseg-12.0.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=apparentlymart/}
PKGREVISION=	11
CATEGORIES=	devel
GITHUB_PROJECT=	go-textseg
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apparentlymart/go-textseg
COMMENT=	Go implementation of Unicode Text Segmentation
LICENSE=	mit AND apache-2.0 AND unicode

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/apparentlymart/go-textseg

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
