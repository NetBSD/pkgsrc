# $NetBSD: Makefile,v 1.2 2015/09/13 14:34:25 bsiegert Exp $
#

DISTNAME=		google-api-go-client
PKGNAME=		google-api-go-client-20150507
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		0297be7525

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://google.golang.org/api/
COMMENT=		Go client library for various Google APIs
LICENSE=		modified-bsd

GO_SRCPATH=		google.golang.org/api
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

.include "../../security/go-oauth2/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
