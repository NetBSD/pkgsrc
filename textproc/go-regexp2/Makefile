# $NetBSD: Makefile,v 1.14 2020/03/21 16:57:18 bsiegert Exp $

DISTNAME=	regexp2-1.1.6
PKGNAME=	go-${DISTNAME}
PKGREVISION=	13
MASTER_SITES=	${MASTER_SITE_GITHUB:=dlclark/}
CATEGORIES=	textproc
GITHUB_PROJECT=	regexp2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dlclark/regexp2
COMMENT=	Regex engine for Go based on the .NET engine
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/dlclark/regexp2

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
