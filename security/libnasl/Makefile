# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:23 jmmv Exp $
#

DISTNAME=	libnasl-${VERS}
WRKSRC=		${WRKDIR}/libnasl
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

DEPENDS+=       nessus-libraries-${VERS}:../nessus-libraries

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}

.include "../../mk/bsd.pkg.mk"
