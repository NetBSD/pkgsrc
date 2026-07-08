# $NetBSD: Makefile,v 1.2 2026/07/08 18:32:40 bsiegert Exp $

DISTNAME=	gatus-5.36.0
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_GITHUB:=TwiN/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/TwiN/gatus/
COMMENT=	Developer-oriented health dashboard for monitoring services
LICENSE=	apache-2.0

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
