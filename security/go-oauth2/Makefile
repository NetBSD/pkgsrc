# $NetBSD: Makefile,v 1.1 2015/05/11 13:27:16 bsiegert Exp $
#

DISTNAME=		oauth2
PKGNAME=		go-${DISTNAME}-20150508
GITHUB_PROJECT=		${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_TAG=		2159a45684

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
