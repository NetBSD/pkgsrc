# $NetBSD: Makefile,v 1.14 2023/11/10 15:45:10 bsiegert Exp $

DISTNAME=	gotags-1.4.1
PKGNAME=	go-${DISTNAME}
PKGREVISION=	13
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
