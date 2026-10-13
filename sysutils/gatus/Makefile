# $NetBSD: Makefile,v 1.9 2026/10/13 18:37:58 bsiegert Exp $

DISTNAME=	gatus-5.37.0
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_GITHUB:=TwiN/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/TwiN/gatus/
COMMENT=	Developer-oriented health dashboard for monitoring services
LICENSE=	apache-2.0

USE_LANGUAGES=	c

GO_VERSION_REQD=	126

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
