# $NetBSD: Makefile,v 1.3 2002/08/04 11:46:54 tron Exp $
#

DISTNAME=	nessus-plugins-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nessus-core-${VERS}:../nessus-core
DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
