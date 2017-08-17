# $NetBSD: Makefile,v 1.1 2017/08/17 01:28:52 gavan Exp $

DISTNAME=	go-homedir-0.0.20161203
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitchellh/}
CATEGORIES=	devel
GITHUB_TAG=	b8bc1bf767474819792c23f32d8286a45736f1c6

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitchellh/go-homedir
COMMENT=	Go library for detecting and expanding the user's home directory without cgo.
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/mitchellh/go-homedir

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

