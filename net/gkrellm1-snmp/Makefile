# $NetBSD: Makefile,v 1.5 2004/03/29 16:27:30 cube Exp $

DISTNAME=		gkrellm_snmp-0.18
PKGNAME=		gkrellm-snmp-0.18
PKGREVISION=		9
CATEGORIES=		net sysutils
MASTER_SITES=		http://triq.net/gkrellm/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://triq.net/gkrellm.html
COMMENT=		Simple SNMP monitor for gkrellm

USE_BUILDLINK2=		# defined
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellm_snmp.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../graphics/imlib/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/gkrellm1/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
