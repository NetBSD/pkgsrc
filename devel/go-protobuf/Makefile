# $NetBSD: Makefile,v 1.4 2016/12/04 16:29:58 bsiegert Exp $

DISTNAME=		go-protobuf-20160829
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		protobuf
GITHUB_TAG=		1f49d83

HOMEPAGE=		http://godoc.org/${GO_SRCPATH}
COMMENT=		Go support for Google protocol buffers
LICENSE=		modified-bsd

GO_SRCPATH=		github.com/golang/protobuf
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

REPLACE_SH+=		ptypes/regen.sh

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
