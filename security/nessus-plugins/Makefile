# $NetBSD: Makefile,v 1.1.1.1 2000/07/30 11:16:15 frueauf Exp $
#

DISTNAME=	nessus-plugins-${VERS}
.include	"../nessus/Makefile.common"

DEPENDS+=	nessus-core-${VERS}:../nessus-core
DEPENDS+=	nmap-2.*:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
