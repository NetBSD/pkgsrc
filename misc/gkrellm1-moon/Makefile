# $NetBSD: Makefile,v 1.4 2004/03/18 15:33:21 cube Exp $

DISTNAME=	gkrellmoon-0.3
PKGNAME=	gkrellm-moon-0.3
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellmoon.sourceforge.net/
COMMENT=	gkrellm moonclock plugin

USE_BUILDLINK3=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
