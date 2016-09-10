# $NetBSD: Makefile,v 1.7 2016/09/10 19:47:21 bsiegert Exp $
#

DISTNAME=		oauth2
PKGNAME=		go-${DISTNAME}-20151204
PKGREVISION=		4
GITHUB_PROJECT=		${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_TAG=		2baa8a1b93

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		OAuth 2 library for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/oauth2
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

.include "../../textproc/go-text/buildlink3.mk"
.include "../../net/gcloud-golang-metadata/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
