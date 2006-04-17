# $NetBSD: Makefile,v 1.8 2006/04/17 13:46:40 wiz Exp $

DISTNAME=	gkrellmoon-0.3
PKGNAME=	gkrellm-moon-0.3
PKGREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellmoon.sourceforge.net/
COMMENT=	gkrellm moonclock plugin


pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
