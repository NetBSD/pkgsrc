# $NetBSD: Makefile,v 1.9 2003/11/12 03:39:41 jschauma Exp $

DISTNAME=		gkrellm_snmp-0.18
PKGNAME=		gkrellm-snmp-0.18
PKGREVISION=		5
CATEGORIES=		net sysutils
MASTER_SITES=		http://triq.net/gkrellm/

MAINTAINER=		jasper@pointless.net
HOMEPAGE=		http://triq.net/gkrellm.html
COMMENT=		Simple SNMP monitor for gkrellm

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellm_snmp.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../graphics/imlib/buildlink2.mk"
.include "../../net/ucd-snmp/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
