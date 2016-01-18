# $NetBSD: Makefile,v 1.4 2016/01/18 15:33:44 fhajny Exp $
#

DISTNAME=		google-api-go-client
PKGNAME=		google-api-go-client-20151217
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		dc6d2353af

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://google.golang.org/api/
COMMENT=		Go client library for various Google APIs
LICENSE=		modified-bsd

GO_SRCPATH=		google.golang.org/api
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

.include "../../security/go-oauth2/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
