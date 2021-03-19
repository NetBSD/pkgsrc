# $NetBSD: Makefile,v 1.33 2021/03/19 17:36:51 bsiegert Exp $

DISTNAME=	golang-lru-0.5.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	12
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
CATEGORIES=	devel
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/golang-lru
COMMENT=	Golang LRU cache
LICENSE=	mpl-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/hashicorp/golang-lru

EXTRACT_USING=	bsdtar

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
