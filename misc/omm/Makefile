# $NetBSD: Makefile,v 1.2 2024/08/11 15:57:03 bsiegert Exp $

DISTNAME=	omm-0.3.1
PKGREVISION=	1
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
