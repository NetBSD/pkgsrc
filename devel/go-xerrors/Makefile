# $NetBSD: Makefile,v 1.11 2020/11/08 21:59:24 bsiegert Exp $
#

DISTNAME=		go-xerrors-20190719
PKGREVISION=		10
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		xerrors
GITHUB_TAG=		9bdfabe685

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://golang.org/x/xerrors
COMMENT=		Transition package for Go 1.13 error values
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/xerrors
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
