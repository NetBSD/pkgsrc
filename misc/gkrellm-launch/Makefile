# $NetBSD: Makefile,v 1.52 2020/03/08 16:50:31 wiz Exp $
#

DISTNAME=	gkrellmlaunch-0.5
PKGNAME=	${DISTNAME:S/gkrellm/gkrellm-/}
PKGREVISION=	41
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellmlaunch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gkrellmlaunch.sourceforge.net/
COMMENT=	GKrellM plugin to allow quick launch of applications

BUILD_TARGET=	gkrellmlaunch.so

USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	lib/gkrellm2/plugins

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellmlaunch.so \
		${DESTDIR}${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
