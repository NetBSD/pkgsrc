# $NetBSD: Makefile,v 1.8 2003/07/13 13:53:11 wiz Exp $
#

DISTNAME=	nessus-plugins-${VERS}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/nessus-plugins
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../security/nessus-core/buildlink2.mk"
.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
