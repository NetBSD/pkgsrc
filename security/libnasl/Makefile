# $NetBSD: Makefile,v 1.6 2004/01/20 12:25:34 agc Exp $

DISTNAME=	libnasl-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../nessus-libraries/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
