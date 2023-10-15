# $NetBSD: Makefile,v 1.11 2023/10/15 12:04:30 bsiegert Exp $

DISTNAME=	oauth2c-1.1.0
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=cloudentity/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cloudentity/oauth2c/
COMMENT=	User-friendly CLI for OAuth2
LICENSE=	apache-2.0

USE_LANGUAGES=	c # go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
