# $NetBSD: Makefile,v 1.7 2003/06/09 17:01:26 frueauf Exp $
#

DISTNAME=	nessus-plugins-${VERS}
WRKSRC=		${WRKDIR}/nessus-plugins
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../security/nessus-core/buildlink2.mk"
.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
