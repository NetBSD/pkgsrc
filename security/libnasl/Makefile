# $NetBSD: Makefile,v 1.1.1.1 2000/07/30 11:11:25 frueauf Exp $
#

DISTNAME=	libnasl-${VERS}
.include	"../nessus/Makefile.common"

DEPENDS+=       nessus-libraries-${VERS}:../nessus-libraries

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}

.include "../../mk/bsd.pkg.mk"
