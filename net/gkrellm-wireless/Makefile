# $NetBSD: Makefile,v 1.43 2013/06/04 22:16:53 tron Exp $

DISTNAME=		gkrellmwireless-2.0.3
PKGNAME=		${DISTNAME:S/gkrellm/gkrellm-/}
PKGREVISION=		24
CATEGORIES=		net sysutils
MASTER_SITES=		http://gkrellm.luon.net/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gkrellm.luon.net/gkrellmwireless.phtml
COMMENT=		Wavelan signal strength monitor for gkrellm

WRKSRC=			${WRKDIR}/gkrellmwireless
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS=	lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
