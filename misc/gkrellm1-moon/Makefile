# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:08 joerg Exp $

DISTNAME=	gkrellmoon-0.3
PKGNAME=	gkrellm-moon-0.3
PKGREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellmoon.sourceforge.net/
COMMENT=	gkrellm moonclock plugin


pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
