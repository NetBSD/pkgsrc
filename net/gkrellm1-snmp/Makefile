# $NetBSD: Makefile,v 1.7 2004/10/03 00:17:52 tv Exp $

DISTNAME=		gkrellm_snmp-0.18
PKGNAME=		gkrellm-snmp-0.18
PKGREVISION=		10
CATEGORIES=		net sysutils
MASTER_SITES=		http://triq.net/gkrellm/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://triq.net/gkrellm.html
COMMENT=		Simple SNMP monitor for gkrellm

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellm_snmp.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../graphics/imlib/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
