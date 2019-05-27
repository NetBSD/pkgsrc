# $NetBSD: Makefile,v 1.14 2019/05/27 15:18:20 bsiegert Exp $
#

DISTNAME=		go-glog-20160125
PKGREVISION=		13
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
