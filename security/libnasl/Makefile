# $NetBSD: Makefile,v 1.5 2003/11/12 16:12:22 tron Exp $

DISTNAME=	libnasl-${VERS}
WRKSRC=		${WRKDIR}/libnasl
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../nessus-libraries/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
