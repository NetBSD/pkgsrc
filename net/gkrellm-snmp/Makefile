# $NetBSD: Makefile,v 1.2 2001/11/01 15:33:02 damon Exp $

DISTNAME=		gkrellm_snmp-0.18
PKGNAME=		gkrellm-snmp-0.18
CATEGORIES=		net sysutils
MASTER_SITES=		http://triq.net/gkrellm/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://triq.net/gkrellm.html
COMMENT=		simple snmp monitor for gkrellm

DEPENDS+=		gkrellm-1.2.*:../../sysutils/gkrellm
DEPENDS+=		ucd-snmp>=4.1.0:../../net/ucd-snmp

USE_GMAKE=		#defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellm_snmp.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../mk/bsd.prefs.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
