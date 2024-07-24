# $NetBSD: Makefile,v 1.1 2024/07/24 18:15:31 ktnb Exp $

DISTNAME=	omm-0.3.1
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
