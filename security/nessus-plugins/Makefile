# $NetBSD: Makefile,v 1.4 2002/10/25 12:32:10 wiz Exp $
#

DISTNAME=	nessus-plugins-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../security/nessus-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
