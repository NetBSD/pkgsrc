# $NetBSD: Makefile,v 1.17 2019/10/18 14:58:45 bsiegert Exp $
#

DISTNAME=		go-glog-20160125
PKGREVISION=		16
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
