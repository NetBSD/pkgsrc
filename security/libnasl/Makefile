# $NetBSD: Makefile,v 1.13 2005/02/21 10:08:43 adam Exp $

DISTNAME=	libnasl-${VERS}

.include	"../nessus/Makefile.common"

COMMENT=	Nessus Attack Scripting Language library

WRKSRC=			${WRKDIR}/libnasl
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/nessus-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
