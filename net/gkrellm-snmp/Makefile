# $NetBSD: Makefile,v 1.88 2026/01/27 08:40:20 wiz Exp $
#

DISTNAME=	gkrellm_snmp-1.1
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://triq.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://triq.net/gkrellm_snmp.html
COMMENT=	GKrellM plugin to display values collected from a SNMP agent
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_FLAGS+=	INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q}
MAKE_FLAGS+=	INSTALL_LIB=${INSTALL_LIB:Q}
MAKE_FLAGS+=	PLUGIN_DIR=${PREFIX:Q}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
