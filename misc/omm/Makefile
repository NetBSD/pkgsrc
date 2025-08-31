# $NetBSD: Makefile,v 1.8 2025/08/31 10:02:51 bsiegert Exp $

DISTNAME=	omm-0.5.1
PKGREVISION=	3
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
