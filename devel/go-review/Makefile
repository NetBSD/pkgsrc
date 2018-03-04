# $NetBSD: Makefile,v 1.8 2018/03/04 15:52:16 bsiegert Exp $
#

DISTNAME=		review
PKGNAME=		go-review-20160213
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		36fe892ba0

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Git Codereview plugin used by the Go project
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/review
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
