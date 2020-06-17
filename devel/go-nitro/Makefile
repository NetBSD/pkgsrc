# $NetBSD: Makefile,v 1.23 2020/06/17 09:54:05 bsiegert Exp $

DISTNAME=	nitro-0.0.20131003
PKGNAME=	go-${DISTNAME}
PKGREVISION=	19
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	24d7ef30a12da0bdc5e2eb370a79c659ddccf0e8
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/nitro
COMMENT=	Quick and easy performance analyzer library
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/spf13/nitro

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
