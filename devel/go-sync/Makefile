# $NetBSD: Makefile,v 1.13 2019/12/13 07:44:00 bsiegert Exp $

DISTNAME=	sync-0.0.20190422
PKGNAME=	go-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	${PKGBASE:S/go-//}
GITHUB_TAG=	112230192c580c3556b8cee6403af37a4fc5f28c

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://golang.org/
COMMENT=	Concurrency primitives for Go
LICENSE=	modified-bsd

GO_SRCPATH=	golang.org/x/sync
GO_DIST_BASE=	${PKGBASE:S/go-//}-${GITHUB_TAG}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
