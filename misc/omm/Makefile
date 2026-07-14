# $NetBSD: Makefile,v 1.18.2.1 2026/07/14 00:35:53 maya Exp $

DISTNAME=	omm-0.5.1
PKGREVISION=	14
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dhth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/dhth/omm/
COMMENT=	Terminal-based task manager
LICENSE=	mit

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
