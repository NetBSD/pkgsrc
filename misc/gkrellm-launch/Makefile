# $NetBSD: Makefile,v 1.8 2005/07/21 16:29:53 wiz Exp $
#

DISTNAME=	gkrellmlaunch-0.5
PKGNAME=	${DISTNAME:S/gkrellm/gkrellm-/}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellmlaunch/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gkrellmlaunch.sourceforge.net/
COMMENT=	GKrellM plugin to allow quick launch of applications

BUILD_TARGET=	gkrellmlaunch.so

INSTALLATION_DIRS=	lib/gkrellm2/plugins

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellmlaunch.so ${PREFIX}/lib/gkrellm2/plugins

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
