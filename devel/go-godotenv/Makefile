# $NetBSD: Makefile,v 1.17 2020/04/12 11:01:32 bsiegert Exp $

DISTNAME=	godotenv-1.2.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=joho/}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://godoc.org/github.com/joho/godotenv
COMMENT=	Go port of the Ruby dotenv library
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/joho/godotenv

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
