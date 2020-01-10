# $NetBSD: Makefile,v 1.13 2020/01/10 13:32:20 bsiegert Exp $

DISTNAME=	godotenv-1.2.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=joho/}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://godoc.org/github.com/joho/godotenv
COMMENT=	Go port of the Ruby dotenv library
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/joho/godotenv

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
