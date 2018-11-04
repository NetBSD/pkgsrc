# $NetBSD: Makefile,v 1.8 2018/11/04 18:37:58 bsiegert Exp $
#

DISTNAME=		go-glog-20160125
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		glog
GITHUB_TAG=		23def4e

HOMEPAGE=		http://godoc.org/${GO_SRCPATH}
COMMENT=		Leveled execution logs for Go
LICENSE=		apache-2.0

GO_SRCPATH=		github.com/golang/glog
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
