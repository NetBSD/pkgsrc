# $NetBSD: Makefile,v 1.11 2004/03/26 02:27:53 wiz Exp $
#

DISTNAME=	nessus-plugins-${VERS}
PKGREVISION=	1
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../security/nessus-core/buildlink2.mk"
.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
