# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:25 jlam Exp $

DISTNAME=		gkrellmwireless-0.2.2
PKGNAME=		gkrellm-wireless-0.2.2
PKGREVISION=		6
CATEGORIES=		net sysutils
MASTER_SITES=		http://gkrellm.luon.net/files/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://gkrellm.luon.net/gkrellmwireless.phtml
COMMENT=		Wavelan signal strength monitor for gkrellm

ONLY_FOR_PLATFORM=	*BSD-*-* Linux-*-*

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	lib/gkrellm/plugins

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/wireless.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../graphics/imlib/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
