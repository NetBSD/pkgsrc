# $NetBSD: Makefile,v 1.12 2004/05/03 05:52:55 snj Exp $
#

DISTNAME=	nessus-plugins-${VERS}
PKGREVISION=	1
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

.include "../../security/nessus-core/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
