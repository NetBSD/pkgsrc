# $NetBSD: Makefile,v 1.6 2018/11/04 18:38:00 bsiegert Exp $

DISTNAME=	golang-lru-0.0.20160813
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
CATEGORIES=	devel
GITHUB_TAG=	0a025b7e63adc15a622f29b0b2c4c3848243bbf6
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/golang-lru
COMMENT=	Golang LRU cache
LICENSE=	mpl-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/hashicorp/golang-lru

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
