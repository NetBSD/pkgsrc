# $NetBSD: Makefile,v 1.1.1.1 2001/10/31 00:30:21 damon Exp $

DISTNAME=		gkrellmwireless-0.2.2
PKGNAME=		gkrellm-wireless-0.2.2
CATEGORIES=		net sysutils
MASTER_SITES=		http://gkrellm.luon.net/files/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://gkrellm.luon.net/gkrellmwireless.phtml
COMMENT=		wavelan signal strength monitor for gkrellm

DEPENDS=		gkrellm-1.2.*:../../sysutils/gkrellm

ONLY_FOR_PLATFORM=	*BSD-*-* Linux-*-*

USE_GMAKE=              #defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wireless.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../mk/bsd.prefs.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
