# $NetBSD: Makefile,v 1.8 2004/05/03 05:52:55 snj Exp $

DISTNAME=	libnasl-${VERS}
PKGREVISION=	1
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

.include "../nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
