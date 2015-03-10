# $NetBSD: Makefile,v 1.1 2015/03/10 21:28:45 bsiegert Exp $
#

DISTNAME=		net
PKGNAME=		go-${DISTNAME}-20150310
GITHUB_PROJECT=		${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_TAG=		6dc0abcce2

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary network libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/net
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

.include "../../textproc/go-text/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
