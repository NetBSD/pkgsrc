# $NetBSD: Makefile,v 1.1.1.1 2004/02/24 23:28:35 cube Exp $

DISTNAME=		gkrellmwireless-0.2.2
PKGNAME=		gkrellm-wireless-0.2.2
PKGREVISION=		4
CATEGORIES=		net sysutils
MASTER_SITES=		http://gkrellm.luon.net/files/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://gkrellm.luon.net/gkrellmwireless.phtml
COMMENT=		Wavelan signal strength monitor for gkrellm

ONLY_FOR_PLATFORM=	*BSD-*-* Linux-*-*

USE_BUILDLINK2=		# defined
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/wireless.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../graphics/imlib/buildlink2.mk"
.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
