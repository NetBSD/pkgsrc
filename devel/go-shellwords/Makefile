# $NetBSD: Makefile,v 1.12 2019/08/14 15:45:39 bsiegert Exp $

DISTNAME=	go-shellwords-1.0.3
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v1.0.3
GITHUB_PROJECT=	go-shellwords

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://godoc.org/github.com/mattn/go-shellwords
COMMENT=	Parse line as shell words
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/^v//}
GO_SRCPATH=	github.com/mattn/go-shellwords

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
