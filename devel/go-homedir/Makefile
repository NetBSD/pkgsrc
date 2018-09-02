# $NetBSD: Makefile,v 1.7 2018/09/02 21:21:25 minskim Exp $

DISTNAME=	go-homedir-1.0.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitchellh/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitchellh/go-homedir
COMMENT=	Go library for home directory information
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/mitchellh/go-homedir

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
