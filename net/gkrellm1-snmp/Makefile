# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:25 jlam Exp $

DISTNAME=		gkrellm_snmp-0.18
PKGNAME=		gkrellm-snmp-0.18
PKGREVISION=		10
CATEGORIES=		net sysutils
MASTER_SITES=		http://triq.net/gkrellm/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://triq.net/gkrellm.html
COMMENT=		Simple SNMP monitor for gkrellm

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	lib/gkrellm/plugins

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellm_snmp.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../graphics/imlib/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
