# $NetBSD: Makefile,v 1.17 2005/04/11 21:46:47 tv Exp $
#

DISTNAME=	gkrellm_snmp-0.21
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://triq.net/gkrellm/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://triq.net/gkrellm_snmp.html
COMMENT=	GKrellM plugin to display values collected from a SNMP agent


.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
