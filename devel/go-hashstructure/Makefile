# $NetBSD: Makefile,v 1.2 2018/12/19 15:47:09 bsiegert Exp $

DISTNAME=	hashstructure-1.0.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitchellh/}
CATEGORIES=	devel
GITHUB_PROJECT=	hashstructure
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitchellh/hashstructure
COMMENT=	Get hash values for arbitrary values in Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/mitchellh/hashstructure

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
