# $NetBSD: Makefile,v 1.2 2001/02/17 17:49:51 wiz Exp $
#

DISTNAME=	libnasl-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

DEPENDS+=       nessus-libraries-${VERS}:../nessus-libraries

WRKSRC=		${WRKDIR}/libnasl

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}

.include "../../mk/bsd.pkg.mk"
