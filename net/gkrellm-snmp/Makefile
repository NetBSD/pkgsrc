# $NetBSD: Makefile,v 1.13 2004/03/07 03:58:55 minskim Exp $
#

DISTNAME=	gkrellm_snmp-0.21
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://triq.net/gkrellm/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://triq.net/gkrellm_snmp.html
COMMENT=	GKrellM plugin to display values collected from a SNMP agent

USE_BUILDLINK2=	YES

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
