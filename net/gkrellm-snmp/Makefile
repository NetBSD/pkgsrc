# $NetBSD: Makefile,v 1.12 2004/02/24 23:34:11 cube Exp $
#

DISTNAME=	gkrellm_snmp-0.21
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://triq.net/gkrellm/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://triq.net/gkrellm_snmp.html
COMMENT=	GKrellM plugin to display values collected from a SNMP agent

USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
