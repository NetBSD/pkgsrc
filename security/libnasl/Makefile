# $NetBSD: Makefile,v 1.10 2004/07/22 15:00:20 adam Exp $

DISTNAME=	libnasl-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
