# $NetBSD: Makefile,v 1.5 2018/11/04 18:38:03 bsiegert Exp $

DISTNAME=		go-image-20170405
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		image
GITHUB_TAG=		10ed294

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Package image implements a basic 2-D image library
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/image
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../textproc/go-text/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
