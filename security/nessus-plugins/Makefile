# $NetBSD: Makefile,v 1.2 2001/02/17 17:49:55 wiz Exp $
#

DISTNAME=	nessus-plugins-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nessus-core-${VERS}:../nessus-core
DEPENDS+=	nmap-2.*:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
