# $NetBSD: Makefile,v 1.4 2004/04/25 23:19:10 wiz Exp $

DISTNAME=		gkrellmwireless-0.2.2
PKGNAME=		gkrellm-wireless-0.2.2
PKGREVISION=		5
CATEGORIES=		net sysutils
MASTER_SITES=		http://gkrellm.luon.net/files/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://gkrellm.luon.net/gkrellmwireless.phtml
COMMENT=		Wavelan signal strength monitor for gkrellm

ONLY_FOR_PLATFORM=	*BSD-*-* Linux-*-*

USE_BUILDLINK3=		# defined
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/wireless.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../graphics/imlib/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
