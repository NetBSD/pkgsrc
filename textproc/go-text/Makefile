# $NetBSD: Makefile,v 1.1 2015/03/10 19:57:18 bsiegert Exp $
#

DISTNAME=		text
PKGNAME=		go-text-20150310
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_TAG=		d1927f6997

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary text processing libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/text
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*


.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
