# $NetBSD: Makefile,v 1.4 2003/06/09 17:01:24 frueauf Exp $
#

DISTNAME=	libnasl-${VERS}
WRKSRC=		${WRKDIR}/libnasl
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

DEPENDS+=       nessus-libraries-${VERS}:../nessus-libraries

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
