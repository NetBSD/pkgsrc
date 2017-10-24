# $NetBSD: Makefile,v 1.1 2017/10/24 06:50:54 maya Exp $

DISTNAME=	go-runewidth-0.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v0.0.2
GITHUB_PROJECT=	go-runewidth

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://godoc.org/github.com/mattn/go-runewidth
COMMENT=	Go functions to get fixed width of the character or string
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/^v//}
GO_SRCPATH=	github.com/mattn/go-runewidth

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
