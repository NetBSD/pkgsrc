# $NetBSD: Makefile,v 1.10 2004/01/20 12:25:34 agc Exp $
#

DISTNAME=	nessus-plugins-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../security/nessus-core/buildlink2.mk"
.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
