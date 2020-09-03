# $NetBSD: Makefile,v 1.6 2020/09/03 07:29:41 bsiegert Exp $

GITHUB_PROJECT=	go-radix
GITHUB_TAG=	v1.0.0
DISTNAME=	v1.0.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=armon/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/armon/go-radix/
COMMENT=	Golang implementation of Radix trees
LICENSE=	mit

GO_DIST_BASE=	${PKGNAME_NOREV}
GO_SRCPATH=	github.com/armon/go-radix

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
