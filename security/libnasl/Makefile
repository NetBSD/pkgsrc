# $NetBSD: Makefile,v 1.9 2004/05/19 16:23:34 adam Exp $

DISTNAME=	libnasl-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

.include "../nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
