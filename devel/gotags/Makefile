# $NetBSD: Makefile,v 1.36 2026/05/07 18:49:53 bsiegert Exp $

DISTNAME=	gotags-1.4.1
PKGNAME=	go-${DISTNAME}
PKGREVISION=	35
MASTER_SITES=	${MASTER_SITE_GITHUB:=jstemmer/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	gotags

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jstemmer/gotags/
COMMENT=	Ctags-compatible tag generator for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
GO_SRCPATH=	github.com/jstemmer/gotags

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
