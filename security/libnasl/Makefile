# $NetBSD: Makefile,v 1.7 2004/03/26 02:27:52 wiz Exp $

DISTNAME=	libnasl-${VERS}
PKGREVISION=	1
.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=		${WRKDIR}/libnasl
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../nessus-libraries/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
