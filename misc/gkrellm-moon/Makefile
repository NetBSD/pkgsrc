# $NetBSD: Makefile,v 1.5 2003/05/03 22:16:28 wiz Exp $

DISTNAME=	gkrellmoon-0.3
PKGNAME=	gkrellm-moon-0.3
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://gkrellmoon.sourceforge.net/
COMMENT=	gkrellm moonclock plugin

USE_BUILDLINK2=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
