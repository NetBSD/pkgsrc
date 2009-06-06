# $NetBSD: Makefile,v 1.16 2009/06/06 20:54:55 zafer Exp $
#

DISTNAME=	gkrellflynn-0.8
PKGNAME=	${DISTNAME:S/gkrell/gkrellm-/}
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://bax.comlab.uni-rostock.de/fileadmin/downloads/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://bax.comlab.uni-rostock.de/en/projekte/gkrellflynn.html
COMMENT=	GKrellM2 plugin that shows system load with a DooM marine

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	gkrellm2
INSTALL_TARGET=	installgkrellm2
INSTALLATION_DIRS=	lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
