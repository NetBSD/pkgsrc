# $NetBSD: Makefile,v 1.8 2004/01/03 18:49:46 reed Exp $

DISTNAME=	gkrellmoon-0.3
PKGNAME=	gkrellm-moon-0.3
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellmoon.sourceforge.net/
COMMENT=	gkrellm moonclock plugin

USE_BUILDLINK2=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
